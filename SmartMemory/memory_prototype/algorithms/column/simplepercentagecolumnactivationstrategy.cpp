#include "simplepercentagecolumnactivationstrategy.h"

using namespace algorithms;

SimplePercentageColumnActivationStrategy::SimplePercentageColumnActivationStrategy(double threshold) :
    threshold{threshold}
{

}

void SimplePercentageColumnActivationStrategy::calculate_column_activation(model::CorticalColumnPtr column)
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
    if (percent >= threshold) {
        // need activate column
        column->activate_column_directly();
    }
}
