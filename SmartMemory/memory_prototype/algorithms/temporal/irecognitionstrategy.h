#ifndef IRECOGNITIONSTRATEGY_H
#define IRECOGNITIONSTRATEGY_H

#include <map>

#include <algorithms/cell/icellsidefeedactivationstrategy.h>

#include <model/datatypes.h>
#include <model/memoryregion.h>
#include <model/corticalcolumn.h>
#include <model/memorycell.h>

namespace algorithms {
    class IRecognitionStrategy
    {
    public:
        IRecognitionStrategy();
        virtual ~IRecognitionStrategy() {}

        //
        virtual void make_recognition(
                model::MemoryRegionPtr region,
                ICellSideFeedActivationStrategy* cell_side_feed_activation_strategy,
                std::map<std::string, bool>& column_activation_map
        ) = 0;
    };
}
#endif // IRECOGNITIONSTRATEGY_H
