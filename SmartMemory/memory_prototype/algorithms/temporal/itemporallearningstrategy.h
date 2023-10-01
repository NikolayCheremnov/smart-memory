#ifndef ITEMPORALLEARNINGSTRATEGY_H
#define ITEMPORALLEARNINGSTRATEGY_H


#include <model/datatypes.h>
#include <model/memoryregion.h>
#include <model/corticalcolumn.h>
#include <model/memorycell.h>

namespace algorithms {
    class ITemporalLearningStrategy
    {
    public:
        ITemporalLearningStrategy();
        virtual ~ITemporalLearningStrategy() {}

        //
        virtual void temporal_learning(model::MemoryRegionPtr region) = 0;
    };
}

#endif // ITEMPORALLEARNINGSTRATEGY_H
