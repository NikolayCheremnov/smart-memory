#ifndef MEMORYCELL_H
#define MEMORYCELL_H

#include <map>
#include <vector>

#include "datatypes.h"
#include "memorystructure.h"


namespace model {

    // Cell of memory
    class MemoryCell
            : public MemoryStructure
    {
    public:
        // Cell state enums
        enum class ViewableState {
            FEED_FORWARD,       // active from direct signal
            SIDE_FEED,          // active from lateral (side) signal
            PASSIVE             // not active
        };
    private:
        ViewableState previous_state;
        ViewableState state;
        std::map<MemoryCell*, DendriticSegmentPtr> distal_dendritic_segments;
        std::vector<MemoryCellPtr> connected_cells;
    public:
        MemoryCell();
        //
        void activate_directly();
        void activate_side_feed();
        void deactivate();
        void change_state(ViewableState state);
        // distal synapses
        void connect_cell(MemoryCellPtr source, DendriticSegmentPtr segment);
        std::map<MemoryCell*, DendriticSegmentPtr> get_distal_dendritic_segments();
        size_t get_connected_cells_count() { return connected_cells.size(); }
        MemoryCellPtr get_connected_cell_by_index(size_t index) { return connected_cells[index]; }
        //
        bool is_active_directly();
        bool is_active_side_feed();
        //
        std::string get_cell_visualization();
    };
}

#endif // MEMORYCELL_H
