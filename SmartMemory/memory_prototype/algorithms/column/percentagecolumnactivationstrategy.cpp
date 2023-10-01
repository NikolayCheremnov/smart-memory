#include "percentagecolumnactivationstrategy.h"

using namespace algorithms;

PercentageColumnActivationStrategy::PercentageColumnActivationStrategy(double threshold) :
    threshold{threshold}
{

}

bool PercentageColumnActivationStrategy::calculate_column_activation(model::CorticalColumnPtr column)
{
    auto segment = column->get_proximal_dendritic_segment();
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
