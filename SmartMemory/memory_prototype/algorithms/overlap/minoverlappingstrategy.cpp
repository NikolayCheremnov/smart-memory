#include "minoverlappingstrategy.h"

using namespace algorithms;

MinOverlappingStrategy::MinOverlappingStrategy(double min_overlap)
    : min_overlap{min_overlap}
{

}

std::map<std::string, double> MinOverlappingStrategy::calculate_overlapping(
        model::MemoryRegionPtr region,
        IPulseDispatcherPtr signal_dispatcher,
        ISynapseActivationStrategy* synapse_activation_strategy
)
{
    std::map<std::string, double> overlapping;
    size_t columns_count = region->get_cortical_columns_set_size();
    for (size_t i = 0; i < columns_count; i++) {
        double overlap = 0.0;
        auto column = region->get_cortical_column_by_index(i);
        auto proximal_dendritic_segment = column->get_proximal_dendritic_segment();
        size_t proximal_synapse_count = proximal_dendritic_segment->get_segment_size();
        for (size_t j = 0; j < proximal_synapse_count; j++) {
            auto synapse = proximal_dendritic_segment->get_segment_synapse_by_index(j);
            double synapse_pulse = signal_dispatcher->read_synapse_pulse(synapse);
            synapse->Permanent() += synapse_pulse;
            synapse_activation_strategy->calculate_synapse_activation(synapse);
            overlap += synapse_pulse;
        }
        if (overlap < min_overlap) {
            overlap = 0;
        } else {
            overlap *= column->get_boost();
        }
        overlapping[column->uuid_str()] = overlap;
    }
    return overlapping;
}
