#include "corticalcolumn.h"

using namespace model;

CorticalColumn::CorticalColumn()
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

void CorticalColumn::activate_column_directly()
{
    for (auto cell : column_cells) {
        cell->activate_directly();
    }
}

MemoryCellPtr CorticalColumn::get_column_cell_by_index(size_t index)
{
    if (index >= 0 && index < column_cells.size()) {
        return column_cells[index];
    }
    return nullptr;
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
