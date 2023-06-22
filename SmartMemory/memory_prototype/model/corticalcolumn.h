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
    public:
        CorticalColumn();
        //
        void add_cell(MemoryCellPtr cell); // add cell from bottom
        void add_proximal_synapse(SynapsePtr synapse);
        void activate_column_directly();
        //
        DendriticSegmentPtr get_proximal_dendritic_segment() { return proximal_dendritic_segment; }
        MemoryCellPtr get_column_cell_by_index(size_t index);
        //
        std::vector<std::pair<std::string, std::string>>  get_cells_visualization();
    };
}

#endif // CORTICALCOLUMN_H
