#ifndef ICELLSIDEFEEDACTIVATIONSTRATEGY_H
#define ICELLSIDEFEEDACTIVATIONSTRATEGY_H

#include <model/datatypes.h>
#include <model/memorycell.h>
#include <model/dendriticsegment.h>
#include <model/synapse.h>

namespace algorithms {
    class ICellSideFeedActivationStrategy
    {
    public:
        ICellSideFeedActivationStrategy();
        virtual ~ICellSideFeedActivationStrategy() {}

        //
        virtual void calculate_side_feed_activation(model::MemoryCellPtr cell) = 0;
    };
}

#endif // ICELLSIDEFEEDACTIVATIONSTRATEGY_H
