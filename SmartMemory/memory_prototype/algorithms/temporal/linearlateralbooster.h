#ifndef LINEARLATERALBOOSTER_H
#define LINEARLATERALBOOSTER_H


#include "ilateralcatalyst.h"
#include "ilateralinhibitor.h"

#include <algorithms/segment/segment.h>
#include <algorithms/segment/isegmentactivationstrategy.h>

namespace algorithms {
    class LinearLateralBooster :
            public ILateralInhibitor, public ILateralCatalyst
    {
    private:
        double permanent_factor;
        ISegmentActivationStrategyPtr segment_activation_strategy;

    public:
        LinearLateralBooster(double permanent_factor, ISegmentActivationStrategyPtr segment_activation_strategy);

        //
        void catalyze_lateral_synapses(model::MemoryCellPtr cell) override;
        void inhibite_lateral_synapses(model::MemoryCellPtr cell) override;

    };
}

#endif // LINEARLATERALBOOSTER_H
