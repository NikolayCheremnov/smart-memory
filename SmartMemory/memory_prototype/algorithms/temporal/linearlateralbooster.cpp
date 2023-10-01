#include "linearlateralbooster.h"

using namespace algorithms;

LinearLateralBooster::LinearLateralBooster(double permanent_factor, ISegmentActivationStrategyPtr segment_activation_strategy) :
    permanent_factor{permanent_factor}, segment_activation_strategy{segment_activation_strategy}
{

}

void LinearLateralBooster::catalyze_lateral_synapses(model::MemoryCellPtr cell)
{
    size_t connected_cells_count = cell->get_connected_cells_count();
    for (size_t i = 0; i < connected_cells_count; i++) {
        auto connected_cell = cell->get_connected_cell_by_index(i);
        auto segment = connected_cell->get_distal_dendritic_segments()[cell.get()];
        // segment is active then add new synapse with average permanent value
        // else increase Permanent
        if (segment_activation_strategy->is_dendritic_segment_active(segment)) {
            double average_permanent = segment->get_average_synapses_peermanent();
            auto synapse = model::SynapsePtr(new model::Synapse(average_permanent));
            segment->add_synapse(synapse);
        } else {
            size_t segment_size = segment->get_segment_size();
            for (size_t j = 0; j < segment_size; j++) {
                segment->get_segment_synapse_by_index(j)->Permanent() += permanent_factor;
            }
        }
    }
}

void LinearLateralBooster::inhibite_lateral_synapses(model::MemoryCellPtr cell)
{
    size_t connected_cells_count = cell->get_connected_cells_count();
    for (size_t i = 0; i < connected_cells_count; i++) {
        auto connected_cell = cell->get_connected_cell_by_index(i);
        auto segment = connected_cell->get_distal_dendritic_segments()[cell.get()];
        // decrease all Permanents and remove all strong synapses with permanent that more then average permanent
        double average_permanent = segment->get_average_synapses_peermanent();
        size_t segment_size = segment->get_segment_size();
        for (size_t j = 0; j < segment_size;) {
            auto synapse = segment->get_segment_synapse_by_index(j);
            if (synapse->Permanent() > average_permanent) {
                segment->remove_synapse_by_index(j);
                segment_size--;
            } else {
                segment->get_segment_synapse_by_index(j)->Permanent() -= permanent_factor;
                j++;
            }
        }
    }
}
