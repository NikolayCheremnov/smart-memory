#include "sufficientcellactivationstrategy.h"

using namespace algorithms;

SufficientCellActivationStrategy::SufficientCellActivationStrategy(double threshold) :
    threshold{threshold}
{

}

void SufficientCellActivationStrategy::calculate_side_feed_activation(model::MemoryCellPtr cell)
{
    auto segments = cell->get_distal_dendritic_segments();
    for (const auto &segments_pair : segments) {
        auto segment = segments_pair.second;
        size_t total = segment->get_segment_size();
        if (total == 0) {
            continue;
        }
        size_t activated = 0;
        for (size_t i = 0; i < total; i++) {
            auto synapse = segment->get_segment_synapse_by_index(i);
            if (synapse->is_active()) {
                activated++;
            }
        }
        double percent = activated / total * 100.0;
        //
        if (percent >= threshold) {
            // need activate cell
            cell->activate_side_feed();
            return;
        }
    }
}
