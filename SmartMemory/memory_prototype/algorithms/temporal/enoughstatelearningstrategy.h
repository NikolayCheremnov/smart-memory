#ifndef ENOUGHSTATELEARNINGSTRATEGY_H
#define ENOUGHSTATELEARNINGSTRATEGY_H

#include "temporal.h"
#include "itemporallearningstrategy.h"
#include "ilateralcatalyst.h"
#include "ilateralinhibitor.h"

namespace algorithms {
    class EnoughStateLearningStrategy :
            public ITemporalLearningStrategy
    {
    private:
        ILateralCatalystPtr lateral_catalyst;
        ILateralInhibitorPtr lateral_inhibitor;
    public:
        EnoughStateLearningStrategy(ILateralCatalystPtr lateral_catalyst, ILateralInhibitorPtr lateral_inhibitor);

        //
        void temporal_learning(model::MemoryRegionPtr region) override;
    private:
        void process_cell(model::MemoryCellPtr cell);
    };
}

#endif // ENOUGHSTATELEARNINGSTRATEGY_H
