#include "randommemoryregioninitializer.h"


using namespace algorithms;

RandomMemoryRegionInitializer::RandomMemoryRegionInitializer()
{

}

model::MemoryRegionPtr RandomMemoryRegionInitializer::InitializeMemoryRegion(size_t cortical_columns_count, size_t cortical_column_height,
                                                                             RandomMemoryRegionInitializerArgs args,
                                                                             ISynapseActivationStrategy* synapse_activation_strategy,
                                                                             IColumnActivationStrategy* column_activation_strategy)
{
    // 1. create empty region
    model::MemoryRegionPtr memory_region = InitializeEmptyMemoryRegion(cortical_columns_count, cortical_column_height);
    // 2. add initial proximal synapses
    for (size_t i = 0; i < cortical_columns_count; i++) {
        model::CorticalColumnPtr column = memory_region->get_cortical_column_by_index(i);   // modifiable column
        // adding proximal synapses to column
        size_t proximal_synapses_count = utils::Randomizer::next_int(args.min_column_proximal_synapses, args.max_column_proximal_synapses);
        for (size_t j = 0; j < proximal_synapses_count; j++) {
            // 1. generate synapse with random potential
            double permanent = utils::Randomizer::next_double(args.min_proximal_permanent, args.max_proximal_permanent);
            model::SynapsePtr proximal_synapse = model::SynapsePtr(new model::Synapse(permanent));
            // 2. calculate synapse activation
            synapse_activation_strategy->calculate_synapse_activation(proximal_synapse);
            // 3. add calculated synapse to column
            column->add_proximal_synapse(proximal_synapse); // add proximal synapse
        }
        // calculate column activation
        column_activation_strategy->calculate_column_activation(column);
    }

    return memory_region;
}

model::MemoryRegionPtr RandomMemoryRegionInitializer::InitializeEmptyMemoryRegion(size_t cortical_columns_count,
                                                                                  size_t cortical_column_height)
{
    model::MemoryRegionPtr memory_region = model::MemoryRegionPtr(new model::MemoryRegion());
    // initialize and add columns
    for (uint32_t i = 0; i < cortical_columns_count; i++) {
        model::CorticalColumnPtr column = model::CorticalColumnPtr(new model::CorticalColumn());
        for (uint32_t j = 0; j < cortical_column_height; j++) {
            column->add_cell(model::MemoryCellPtr(new model::MemoryCell()));
        }
        memory_region->add_column(column);
    }
    return memory_region;
}
