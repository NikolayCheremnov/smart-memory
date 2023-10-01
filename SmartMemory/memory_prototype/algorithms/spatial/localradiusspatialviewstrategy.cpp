#include "localradiusspatialviewstrategy.h"

using namespace algorithms;

LocalRadiusSpatialViewStrategy::LocalRadiusSpatialViewStrategy()
{

}

std::vector<model::CorticalColumnPtr> LocalRadiusSpatialViewStrategy::get_neighbors_columns(
        model::MemoryRegionPtr region,
        size_t column_index,
        size_t column_radius
    )
{
    std::vector<model::CorticalColumnPtr> neihbors_columns;
    size_t column_count = region->get_cortical_columns_set_size();
    int32_t start = column_index - column_radius;
    if (start < 0) {
        start = 0;
    }
    int32_t end = column_index + column_radius;
    if (end >= (int32_t)column_count) {
        end = column_count;
    } else {
        end++;  // from
    }
    // create columns set
    for (auto i = start; i < end; i++) {
        if (i != (int32_t)column_index) {
            auto column = region->get_cortical_column_by_index(i);
            neihbors_columns.push_back(column);
        }
    }
    return neihbors_columns;
}

std::vector<model::MemoryCellPtr> LocalRadiusSpatialViewStrategy::get_neighbors_cells(
        model::MemoryRegionPtr region,
        size_t column_index,
        size_t column_radius,
        size_t cell_index,
        size_t cell_radius
    )
{
    std::vector<model::MemoryCellPtr> neihbors_cells;
    auto neihbors_columns = get_neighbors_columns(region, column_index, column_radius);
    for (auto neihbors_column : neihbors_columns) {
        size_t cell_count = neihbors_column->get_column_height();
        int32_t start = cell_index - cell_radius;
        if (start < 0) {
            start = 0;
        }
        int32_t end = cell_index + cell_radius;
        if (end >= (int32_t)cell_count) {
            end = cell_count;
        } else {
            end++;  // from
        }
        // create neihbors cells set
        for (auto i = start; i < end; i++) {
             auto cell = neihbors_column->get_column_cell_by_index(i);
             neihbors_cells.push_back(cell);
        }
    }
    return neihbors_cells;
}
