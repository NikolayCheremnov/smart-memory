#include "dotgenerator.h"

using namespace gu;

DotGenerator::DotGenerator()
{

}

std::string DotGenerator::generate_cellular_memory_frame_as_dot(model::MemoryRegionPtr region)
{
    std::ostringstream out;
    out << "digraph G{\n";
    auto colums_set_size = region->get_cortical_columns_set_size();
    for (uint32_t i = 0; i < colums_set_size; i++) {
        auto column = region->get_cortical_column_by_index(i);
        out << column_cells_as_dot(column, i);
        out << column_proximal_synapses_as_dot(column, "input");
    }
    out << "}";
    return out.str();
}

std::string DotGenerator::generate_total_memory_frame_as_dot(model::MemoryRegionPtr region)
{
    std::ostringstream out;
    out << "digraph G{\nnode [style=\"rounded,filled\"];\n";
    auto colums_set_size = region->get_cortical_columns_set_size();
    for (uint32_t i = 0; i < colums_set_size; i++) {
        auto column = region->get_cortical_column_by_index(i);
        // 1. add proximal_synapses as dot
        out << column_proximal_synapses_as_dot(column, "input");
        // 2. add cells and dendritic synapses
        out << total_cells_as_dot(column);
    }
    out << "}";
    return out.str();
}

std::string DotGenerator::total_cells_as_dot(model::CorticalColumnPtr column)
{
    std::ostringstream out;
    // 1. output cells and chain into column
    auto cells_viz_data = column->get_cells_visualization();
    std::vector<std::string> short_cells_uuids;
    for (const auto &viz_data : cells_viz_data) {
        out << "\t\"" << viz_data.first << "\" [fillcolor=\"" << viz_data.second << "\"];\n";
        short_cells_uuids.push_back(viz_data.first);
    }
    for (size_t i = 0; i < short_cells_uuids.size() - 1; i++) {
        out << "\t\"" << short_cells_uuids[i] << "\"->\"" << short_cells_uuids[i+1] << "\";\n";
    }
    // 2. output distal synapses
    size_t column_height = column->get_column_height();
    for (size_t i = 0; i < column_height; i++) {
        auto cell = column->get_column_cell_by_index(i);
        auto segments = cell->get_distal_dendritic_segments();
        for (const auto &segment_pair : segments) {
            model::MemoryCell* source_cell = segment_pair.first;
            model::DendriticSegmentPtr segment = segment_pair.second;
            auto segment_size = segment->get_segment_size();
            for (size_t j = 0; j < segment_size; j++) {
                auto synapse = segment->get_segment_synapse_by_index(j);
                out << "\t\"" << source_cell->short_uuid_str() << "\"->\"" << cell->short_uuid_str() << "\"" <<
                       "[label=\"" << synapse->Permanent() << "\",color=\"" <<
                       synapse->get_synapse_visualization() << "\"];\n";
            }
        }
    }
    return out.str();
}

std::string DotGenerator::column_cells_as_dot(model::CorticalColumnPtr column, size_t column_index)
{
    std::ostringstream out;
    out << "\tsubgraph cluster_" << column_index << "{\n" <<
           "\t\tnode [style=\"rounded,filled\"];\n";
    auto cells_viz_data = column->get_cells_visualization();
    std::vector<std::string> short_cells_uuids;
    for (const auto &viz_data : cells_viz_data) {
        out << "\t\t\"" << viz_data.first << "\" [fillcolor=\"" << viz_data.second << "\"];\n";
        short_cells_uuids.push_back(viz_data.first);
    }
    for (size_t i = 0; i < short_cells_uuids.size() - 1; i++) {
        out << "\t\t\"" << short_cells_uuids[i] << "\"->\"" << short_cells_uuids[i+1] << "\";\n";
    }
    out << "\t\tlabel=\"" << column->short_uuid_str() << "(" << column->get_boost() << ")" << "\";\n" <<
           "\t\tcolor=black;\n\t}\n";
    return out.str();
}

std::string DotGenerator::column_proximal_synapses_as_dot(model::CorticalColumnPtr column, std::string input_label)
{
    std::ostringstream out;
    auto segment = column->get_proximal_dendritic_segment();
    size_t segment_size = segment->get_segment_size();
    auto top_cell = column->get_column_cell_by_index(0);
    for (size_t i = 0; i < segment_size; i++) {
        auto synapse = segment->get_segment_synapse_by_index(i);
        out << "\t\"" << input_label << "\"->\"" << top_cell->short_uuid_str() <<
               "\"[label=\"" << synapse->Permanent() << "\",color=\"" <<
               synapse->get_synapse_visualization() << "\"];\n";
    }
    return out.str();
}
