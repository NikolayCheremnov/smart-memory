#ifndef IOVERLAPPINGSTRATEGY_H
#define IOVERLAPPINGSTRATEGY_H

#include <map>

#include <model/datatypes.h>
#include <model/memoryregion.h>

#include <algorithms/synapse/isynapseactivationstrategy.h>
#include <algorithms/column/icolumninputstrategy.h>
#include <algorithms/sensor/sensor.h>
#include <algorithms/sensor/ipulsedispatcher.h>

namespace algorithms {

    class IOverlappingStrategy
    {
    public:
        IOverlappingStrategy();
        virtual ~IOverlappingStrategy(){};
        virtual std::map<std::string, double> calculate_overlapping(
                model::MemoryRegionPtr region,
                IPulseDispatcherPtr signal_dispatcher,
                ISynapseActivationStrategy* synapse_activation_strategy
        ) = 0;
    };
}

#endif // IOVERLAPPINGSTRATEGY_H
