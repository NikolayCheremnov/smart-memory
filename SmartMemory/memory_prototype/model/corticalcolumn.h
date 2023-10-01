#ifndef CORTICALCOLUMN_H
#define CORTICALCOLUMN_H

#include <vector>
#include <map>

#include "datatypes.h"
#include "memorystructure.h"
#include "memorycell.h"
#include "dendriticsegment.h"


namespace model {

    // Cortical column have set of cells
    class CorticalColumn :
            public MemoryStructure
    {
    private:
        std::vector<MemoryCellPtr> column_cells;
        DendriticSegmentPtr proximal_dendritic_segment;
        // column influence fields
        double boost;   // column agression boost factor
        size_t inhibition_radius;
        // temporal column data
        size_t time_after_last_win;
        size_t time_after_last_lose;
    public:
        CorticalColumn(double boost, size_t inhibition_radius);
        //
        void add_cell(MemoryCellPtr cell); // add cell from bottom
        void add_proximal_synapse(SynapsePtr synapse);

        //
        DendriticSegmentPtr get_proximal_dendritic_segment() { return proximal_dendritic_segment; }
        size_t get_column_height() { return column_cells.size(); }
        MemoryCellPtr get_column_cell_by_index(size_t index);
        double get_boost() { return boost; }
        void set_boost(double boost) { this->boost = boost; }
        size_t get_inhibition_radius() { return inhibition_radius; }
        size_t get_time_after_last_win() { return time_after_last_win; }
        size_t get_time_after_last_lose() { return time_after_last_lose; }
        void temporal_tick(bool is_active);
        //
        bool is_all_column_active();
        //
        std::vector<std::pair<std::string, std::string>>  get_cells_visualization();
    };
}

#endif // CORTICALCOLUMN_H
