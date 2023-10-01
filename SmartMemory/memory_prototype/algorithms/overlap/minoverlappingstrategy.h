#ifndef MINOVERLAPPINGSTRATEGY_H
#define MINOVERLAPPINGSTRATEGY_H


#include "ioverlappingstrategy.h"

namespace algorithms {
    class MinOverlappingStrategy
            : public IOverlappingStrategy
    {
    private:
        double min_overlap;

    public:
        MinOverlappingStrategy(double min_overlap);

        //
        std::map<std::string, double> calculate_overlapping(
                model::MemoryRegionPtr region,
                IPulseDispatcherPtr signal_dispatcher,
                ISynapseActivationStrategy* synapse_activation_strategy
        ) override;
    };
}

#endif // MINOVERLAPPINGSTRATEGY_H
