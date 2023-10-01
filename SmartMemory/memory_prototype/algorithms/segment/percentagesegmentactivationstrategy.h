#ifndef PERCENTAGESEGMENTACTIVATIONSTRATEGY_H
#define PERCENTAGESEGMENTACTIVATIONSTRATEGY_H


#include "isegmentactivationstrategy.h"

namespace algorithms {
    class PercentageSegmentActivationStrategy :
            public ISegmentActivationStrategy
    {
    private:
        double threshold;   // from 0% to 100% (can use other values, but it *100 yet)
    public:
        PercentageSegmentActivationStrategy(double threshold);

        bool is_dendritic_segment_active(model::DendriticSegmentPtr segment) override;
    };
}

#endif // PERCENTAGESEGMENTACTIVATIONSTRATEGY_H
