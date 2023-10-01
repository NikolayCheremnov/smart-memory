#ifndef LOCALRADIUSSPATIALVIEWSTRATEGY_H
#define LOCALRADIUSSPATIALVIEWSTRATEGY_H


#include "ispatialviewsrategy.h"

namespace algorithms {
    class LocalRadiusSpatialViewStrategy :
            public ISpatialViewSrategy
    {
    public:
        LocalRadiusSpatialViewStrategy();

        //
        std::vector<model::CorticalColumnPtr> get_neighbors_columns(
                model::MemoryRegionPtr region,
                size_t column_index,
                size_t column_radius
        ) override;
        std::vector<model::MemoryCellPtr> get_neighbors_cells(
                model::MemoryRegionPtr region,
                size_t column_index,
                size_t column_radius,
                size_t cell_index,
                size_t cell_radius
        ) override;
    };
}

#endif // LOCALRADIUSSPATIALVIEWSTRATEGY_H
