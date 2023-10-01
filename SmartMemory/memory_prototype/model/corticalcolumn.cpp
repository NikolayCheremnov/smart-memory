#include "corticalcolumn.h"

using namespace model;

CorticalColumn::CorticalColumn(double boost, size_t inhibition_radius) :
    boost{boost}, inhibition_radius{inhibition_radius}, time_after_last_win{0}, time_after_last_lose{0}
{
    proximal_dendritic_segment = DendriticSegmentPtr(new DendriticSegment());
}

void CorticalColumn::add_cell(MemoryCellPtr cell)
{
    column_cells.push_back(cell);
}

void CorticalColumn::add_proximal_synapse(SynapsePtr synapse)
{
    proximal_dendritic_segment->add_synapse(synapse);
}

MemoryCellPtr CorticalColumn::get_column_cell_by_index(size_t index)
{
    if (index >= 0 && index < column_cells.size()) {
        return column_cells[index];
    }
    return nullptr;
}

void CorticalColumn::temporal_tick(bool is_active)
{
    if (is_active) {
        // column was activated
        time_after_last_win = 0;
        time_after_last_lose++;
    } else {
        // column deactevated
        time_after_last_lose = 0;
        time_after_last_win++;
    }
}

bool CorticalColumn::is_all_column_active()
{
    for (const auto& cell : column_cells) {
        if (!cell->is_active_directly()) {
            return false;
        }
    }
    return true;
}

std::vector<std::pair<std::string, std::string>> CorticalColumn::get_cells_visualization()
{
    std::vector<std::pair<std::string, std::string>> cells_visualization_data;
    for (size_t i = 0; i < column_cells.size(); i++) {
        std::pair<std::string, std::string> pair_data(column_cells[i]->short_uuid_str(), column_cells[i]->get_cell_visualization());
         cells_visualization_data.push_back(pair_data);
    }
//    for (MemoryCellPtr cell : column_cells) {
//        cells_visualization_data[cell->short_uuid_str()] = cell->get_cell_visualization();
//    }
    return cells_visualization_data;
}
