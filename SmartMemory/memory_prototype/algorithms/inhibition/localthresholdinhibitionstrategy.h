#ifndef LOCALTHRESHOLDINHIBITIONSTRATEGY_H
#define LOCALTHRESHOLDINHIBITIONSTRATEGY_H

#include <vector>
#include <algorithm>

#include "iinhibitionastrategy.h"

namespace algorithms {

    class LocalThresholdInhibitionStrategy
            : public IInhibitionaStrategy
    {
    private:
        size_t desired_local_activity;
    public:
        LocalThresholdInhibitionStrategy(size_t desired_local_activity);

        //
        std::map<std::string, bool> process_column_inhibition(model::MemoryRegionPtr region, std::map<std::string, double> overlap) override;
    private:
        bool check_best_local_activity(model::MemoryRegionPtr region, size_t column_index, std::map<std::string, double>& overlap);
    };
}

#endif // LOCALTHRESHOLDINHIBITIONSTRATEGY_H
