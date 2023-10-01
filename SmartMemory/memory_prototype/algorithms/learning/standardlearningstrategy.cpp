#include "standardlearningstrategy.h"

using namespace algorithms;

StandardLearningStrategy::StandardLearningStrategy(
        double permanence_inc,
        double permanence_dec,
        double max_permanent,
        double min_permanent,
        double activity_factor,
        double boost_factor,
        double proximal_synapses_permanent_factor
)
    :
      permanence_inc{permanence_inc},
      permanence_dec{permanence_dec},
      max_permanent{max_permanent},
      min_permanent{min_permanent},
      activity_factor{activity_factor},
      boost_factor{boost_factor},
      proximal_synapses_permanent_factor{proximal_synapses_permanent_factor}
{

}

void StandardLearningStrategy::make_learning(
        model::MemoryRegionPtr region,
        std::map<std::string, bool> column_activation_map
)
{
    // 1. change proximal synapses permanent for active columns
    size_t columns_count = region->get_cortical_columns_set_size();
    for (size_t i = 0; i < columns_count; i++) {
        auto column = region->get_cortical_column_by_index(i);
        if (column_activation_map[column->uuid_str()]) {
            // only for column from active column set
            auto proximal_dendritic_segment = column->get_proximal_dendritic_segment();
            size_t proximal_synapse_count = proximal_dendritic_segment->get_segment_size();
            for (size_t j = 0; j < proximal_synapse_count; j++) {
                auto synapse = proximal_dendritic_segment->get_segment_synapse_by_index(j);
                if (synapse->is_active()) {
                    synapse->Permanent() += permanence_inc;
                    if (synapse->Permanent() > max_permanent) {
                        synapse->Permanent() = max_permanent;
                    }
                } else {
                    synapse->Permanent() -= permanence_dec;
                    if (synapse->Permanent() < min_permanent) {
                        synapse->Permanent() = min_permanent;
                    }
                }
            }
        }
    }
    // 2.
    for (size_t i = 0; i < columns_count; i++) {
        auto checked_column = region->get_cortical_column_by_index(i);
        size_t inhibition_distance = checked_column->get_inhibition_radius();
        int32_t start = i - inhibition_distance;
        start = start < 0? 0: start;
        int32_t end = i + inhibition_distance;
        end = end >= (int32_t)columns_count? columns_count : end + 1;
        size_t column_activity = checked_column->get_time_after_last_win();
        size_t max_local_activity = column_activity; // max_local_activity <=> min time from last win
        for (size_t j = start; j < (size_t)end; j++) {
            if (j != i) {
                auto column = region->get_cortical_column_by_index(j);
                size_t local_activity = column->get_time_after_last_win();
                if (local_activity < max_local_activity) {
                    max_local_activity = local_activity;
                }
            }
        }
        size_t min_local_activity = activity_factor * column_activity;
        if (min_local_activity > max_local_activity) {
            // increase boost and proximal synapses permanent
            checked_column->set_boost(checked_column->get_boost() * boost_factor);
            auto proximal_dendritic_segment = checked_column->get_proximal_dendritic_segment();
            size_t segment_size = proximal_dendritic_segment->get_segment_size();
            for (size_t j = 0; j < segment_size; j++) {
                auto synapse = proximal_dendritic_segment->get_segment_synapse_by_index(j);
                synapse->Permanent() *= proximal_synapses_permanent_factor;
            }
        } else {
            checked_column->set_boost(1.0);
        }
    }
}
