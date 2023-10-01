#include "enoughstatelearningstrategy.h"

using namespace algorithms;

EnoughStateLearningStrategy::EnoughStateLearningStrategy(ILateralCatalystPtr lateral_catalyst, ILateralInhibitorPtr lateral_inhibitor) :
    lateral_catalyst{lateral_catalyst}, lateral_inhibitor{lateral_inhibitor}
{

}

void EnoughStateLearningStrategy::temporal_learning(model::MemoryRegionPtr region)
{
    // need to inhibit lateral synapses from deactivated columns and catalyze lateral synapses from active columns
    size_t columns_count = region->get_cortical_columns_set_size();
    for (size_t i = 0; i < columns_count; i++) {
        auto column = region->get_cortical_column_by_index(i);
        // process columns cells
        size_t cells_count = column->get_column_height();
        for (size_t j = 0; j < cells_count; j++) {
            auto cell = column->get_column_cell_by_index(j);
            process_cell(cell);
        }
    }
}

void EnoughStateLearningStrategy::process_cell(model::MemoryCellPtr cell)
{
    if (cell->is_active_side_feed()) {
        // no action for size feed activated cell
        return;
    }
    if (cell->is_active_directly()) {
        // catalyze lateral synapses
        lateral_catalyst->catalyze_lateral_synapses(cell);
    } else {
        // inhibite lateral synapses
        lateral_inhibitor->inhibite_lateral_synapses(cell);
    }
}
