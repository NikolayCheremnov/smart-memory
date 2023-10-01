#include "percentagesegmentactivationstrategy.h"

using namespace algorithms;

PercentageSegmentActivationStrategy::PercentageSegmentActivationStrategy(double threshold) :
    threshold{threshold}
{

}

bool PercentageSegmentActivationStrategy::is_dendritic_segment_active(model::DendriticSegmentPtr segment)
{
    size_t total = segment->get_segment_size();
    double activated = 0;
    for (size_t i = 0; i < total; i++) {
        if (segment->get_segment_synapse_by_index(i)->is_active()) {
            activated++;
        }
    }
    double percent = activated / total * 100.0;
    //
    return percent >= threshold;
}
