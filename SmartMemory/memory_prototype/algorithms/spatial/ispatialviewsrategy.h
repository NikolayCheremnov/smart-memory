#ifndef ISPATIALVIEWSRATEGY_H
#define ISPATIALVIEWSRATEGY_H


#include <vector>

#include <model/datatypes.h>
#include <model/memoryregion.h>
#include <model/corticalcolumn.h>

namespace algorithms {
    class ISpatialViewSrategy
    {
    public:
        ISpatialViewSrategy();
        virtual ~ISpatialViewSrategy() {}

        // spatial methods
        virtual std::vector<model::CorticalColumnPtr> get_neighbors_columns(
                model::MemoryRegionPtr region,
                size_t column_index,
                size_t column_radius
        ) = 0;
        virtual std::vector<model::MemoryCellPtr> get_neighbors_cells(
                model::MemoryRegionPtr region,
                size_t column_index,
                size_t column_radius,
                size_t cell_index,
                size_t cell_radius
        ) = 0;
    };
}

#endif // ISPATIALVIEWSRATEGY_H
