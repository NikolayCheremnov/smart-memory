#include "localthresholdinhibitionstrategy.h"

using namespace algorithms;

LocalThresholdInhibitionStrategy::LocalThresholdInhibitionStrategy(size_t desired_local_activity)
    : desired_local_activity{desired_local_activity}
{

}

std::map<std::string, bool> LocalThresholdInhibitionStrategy::process_column_inhibition(model::MemoryRegionPtr region, std::map<std::string, double> overlap)
{
    std::map<std::string, bool> column_activation_map;
    size_t column_count = region->get_cortical_columns_set_size();
    std::vector<model::CorticalColumnPtr> active_columns;
    std::vector<model::CorticalColumnPtr> passive_columns;
    // group columns by activity
    for (size_t i = 0; i < column_count; i++) {
        auto column = region->get_cortical_column_by_index(i);
        bool is_active = check_best_local_activity(region, i, overlap);
        column_activation_map[column->uuid_str()] = is_active;
        column->temporal_tick(is_active);
    }
    return column_activation_map;
}

bool LocalThresholdInhibitionStrategy::check_best_local_activity(model::MemoryRegionPtr region, size_t column_index, std::map<std::string, double> &overlap)
{
    size_t column_count = region->get_cortical_columns_set_size();
    auto checked_column = region->get_cortical_column_by_index(column_index);
    if (overlap[checked_column->uuid_str()] <= 0) {
        return false;
    }
    // check for best overlap in readius
    size_t inhibition_distance = checked_column->get_inhibition_radius();
    int32_t start = column_index - inhibition_distance;
    start = start < 0? 0: start;
    int32_t end = column_index + inhibition_distance;
    end = end >= (int32_t)column_count? column_count : end + 1;
    if (end - start - 1 < (int32_t)desired_local_activity) {
        return false;   // not enought local activity columns
    }
    size_t local_max = overlap[checked_column->uuid_str()];
    for (size_t i = start; i < (size_t)end; i++) {
        if (i != column_index) {
            auto column = region->get_cortical_column_by_index(i);
            if (overlap[column->uuid_str()] > local_max) {
                return false;
            }
        }
    }
    return true;
}
