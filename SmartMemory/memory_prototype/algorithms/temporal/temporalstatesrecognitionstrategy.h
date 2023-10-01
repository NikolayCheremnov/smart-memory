#ifndef TEMPORALSTATESRECOGNITIONSTRATEGY_H
#define TEMPORALSTATESRECOGNITIONSTRATEGY_H


#include "irecognitionstrategy.h"

namespace algorithms {
    class TemporalStatesRecognitionStrategy :
            public IRecognitionStrategy
    {
    public:
        TemporalStatesRecognitionStrategy();

        void make_recognition(
                model::MemoryRegionPtr region,
                ICellSideFeedActivationStrategy* cell_side_feed_activation_strategy,
                std::map<std::string, bool>& column_activation_map
        ) override;
    };
}

#endif // TEMPORALSTATESRECOGNITIONSTRATEGY_H
