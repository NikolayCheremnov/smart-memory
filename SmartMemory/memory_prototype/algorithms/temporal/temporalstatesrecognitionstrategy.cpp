#include "temporalstatesrecognitionstrategy.h"


using namespace algorithms;

TemporalStatesRecognitionStrategy::TemporalStatesRecognitionStrategy()
{

}

void TemporalStatesRecognitionStrategy::make_recognition(
        model::MemoryRegionPtr region,
        ICellSideFeedActivationStrategy* cell_side_feed_activation_strategy,
        std::map<std::string, bool>& column_activation_map
)
{
    size_t columns_count = region->get_cortical_columns_set_size();
    // 1. calculate cells directly activation
    for (size_t i = 0; i < columns_count; i++) {
        auto column = region->get_cortical_column_by_index(i);
        if (column_activation_map[column->uuid_str()]) {
            size_t cells_count = column->get_column_height();
            bool need_activate_all_column = true;
            for (size_t j = 0; j < cells_count; j++) {
                auto cell = column->get_column_cell_by_index(j);
                if (cell->is_active_side_feed()) {
                    need_activate_all_column = false;
                    break;
                }
            }
            for (size_t j = 0; j < cells_count; j++) {
                auto cell = column->get_column_cell_by_index(j);
                if (need_activate_all_column || cell->is_active_side_feed()) {
                    cell->activate_directly();
                };
            }
        }
    }
    // 2. calculate cells side feed activation (for not activated columns)
    for (size_t i = 0; i < columns_count; i++) {
        auto column = region->get_cortical_column_by_index(i);
        if (!column_activation_map[column->uuid_str()]) {
            size_t cells_count = column->get_column_height();
            for (size_t j = 0; j < cells_count; j++) {
                auto cell = column->get_column_cell_by_index(j);
                cell->deactivate(); // deactivate cell in not activated columns
                cell_side_feed_activation_strategy->calculate_side_feed_activation(cell);
            }
        }
    }
}
