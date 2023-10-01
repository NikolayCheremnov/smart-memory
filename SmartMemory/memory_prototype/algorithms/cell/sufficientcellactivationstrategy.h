#ifndef SUFFICIENTCELLACTIVATIONSTRATEGY_H
#define SUFFICIENTCELLACTIVATIONSTRATEGY_H


#include "icellsidefeedactivationstrategy.h"

namespace algorithms {
    class SufficientCellActivationStrategy :
            public ICellSideFeedActivationStrategy
    {
    private:
        double threshold;   // from 0% to 100% (can use other values, but it *100 yet)
    public:
        SufficientCellActivationStrategy(double threshold);

        //
        void calculate_side_feed_activation(model::MemoryCellPtr cell) override;
    };
}

#endif // SUFFICIENTCELLACTIVATIONSTRATEGY_H
