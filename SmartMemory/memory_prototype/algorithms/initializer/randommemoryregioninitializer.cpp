#include "randommemoryregioninitializer.h"


using namespace algorithms;

RandomMemoryRegionInitializer::RandomMemoryRegionInitializer()
{

}

void RandomMemoryRegionInitializer::initialize_memory_region(
        model::MemoryRegionPtr region,
        SynapsesInitializerArgs args,
        size_t distal_radius,
        ISynapseActivationStrategy* synapse_activation_strategy,
        ISpatialViewSrategy* spatial_view_strategy,
        IColumnActivationStrategy* column_activation_strategy,
        IRecognitionStrategy* recognition_strategy,
        ICellSideFeedActivationStrategy* cell_side_feed_activation_strategy
)
{
    // 1. primary proximal synapses intialization and column activations calculation
    // and add some side feed activated cells to potential active columns
    size_t columns_count = region->get_cortical_columns_set_size();
    std::map<std::string, bool> column_activation_map;
    for (size_t i = 0; i < columns_count; i++) {
        auto column = region->get_cortical_column_by_index(i);
        initialize_proximal_synapses(column, args, synapse_activation_strategy);
        bool is_column_activated = column_activation_strategy->calculate_column_activation(column);
        column_activation_map[column->uuid_str()] = is_column_activated;
        if (is_column_activated) {
            if (utils::Randomizer::next_bool()) {
                // we add random preactivated cells
                size_t column_height = column->get_column_height();
                for (size_t j = 0; j < column_height; j++) {
                    auto cell = column->get_column_cell_by_index(j);
                    if (utils::Randomizer::next_bool() && utils::Randomizer::next_bool()) {
                        cell->activate_side_feed();
                    }
                }
            }
        }
    }
    // 2. make recognition for active columns (without distal)
    recognition_strategy->make_recognition(region, cell_side_feed_activation_strategy, column_activation_map);
    // 3. add distal synapses only for activated cells and activate distal
    initialize_distal_synapses(region, args, distal_radius, synapse_activation_strategy, spatial_view_strategy, cell_side_feed_activation_strategy);
}

void RandomMemoryRegionInitializer::initialize_proximal_synapses(
        model::CorticalColumnPtr column,
        SynapsesInitializerArgs args,
        ISynapseActivationStrategy *synapse_activation_strategy
)
{
    // adding proximal synapses to column
    size_t proximal_synapses_count = utils::Randomizer::next_int(args.min_proximal_synapses, args.max_proximal_synapses);
    for (size_t j = 0; j < proximal_synapses_count; j++) {
        // 1. generate synapse with random potential
        double permanent = utils::Randomizer::next_double(args.min_proximal_permanent, args.max_proximal_permanent);
        model::SynapsePtr proximal_synapse = model::SynapsePtr(new model::Synapse(permanent));
        // 2. calculate synapse activation
        synapse_activation_strategy->calculate_synapse_activation(proximal_synapse);
        // 3. add calculated synapse to column
        column->add_proximal_synapse(proximal_synapse); // add proximal synapse
    }
}

void RandomMemoryRegionInitializer::initialize_distal_synapses(
        model::MemoryRegionPtr region,
        SynapsesInitializerArgs args,
        size_t distal_radius,
        ISynapseActivationStrategy* synapse_activation_strategy,
        ISpatialViewSrategy* spatial_view_strategy,
        ICellSideFeedActivationStrategy* cell_side_feed_activation_strategy
)
{
    size_t column_count = region->get_cortical_columns_set_size();
    for (size_t i = 0; i < column_count; i++) {
        auto column = region->get_cortical_column_by_index(i);
        size_t column_height = column->get_column_height(); // number of cells in column
        for (size_t j = 0; j < column_height; j++) {
            auto cell = column->get_column_cell_by_index(j);
            // need to add distal dendritic segments to column with given arguments
            auto neihbors_cells = spatial_view_strategy->get_neighbors_cells(region, i, distal_radius, j, distal_radius);
            // add dendritic segmenets between cell and neihbors cells
            for (auto neihbors_cell : neihbors_cells) {
                // make synapses
                size_t synapses_count = utils::Randomizer::next_int(args.min_distal_synapses, args.max_distal_synapses);
                model::DendriticSegmentPtr segment = model::DendriticSegmentPtr(new model::DendriticSegment());
                for (size_t k = 0; k < synapses_count; k++) {
                    // 1. generate synapse with random potential
                    model::SynapsePtr synapse;
                    do {
                        double permanent = utils::Randomizer::next_double(args.min_distal_permanent, args.max_distal_permanent);
                        synapse = model::SynapsePtr(new model::Synapse(permanent));
                        synapse_activation_strategy->calculate_synapse_activation(synapse);
                    } while (!cell->is_active_directly() && synapse->is_active());
                    segment->add_synapse(synapse);
                }
                neihbors_cell->connect_cell(cell, segment);
                // TODO: нельзя допускать клеток в состоянии предсказания в активном столбце (либо делать связи только к активным "победившим" клеткам
                // эмулируется реальная ситуация
                cell_side_feed_activation_strategy->calculate_side_feed_activation(neihbors_cell);
            }
        }
    }
}
