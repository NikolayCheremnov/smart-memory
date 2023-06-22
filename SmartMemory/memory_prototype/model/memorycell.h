#ifndef MEMORYCELL_H
#define MEMORYCELL_H

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
        ViewableState state;
        std::vector<DendriticSegmentPtr> distal_dendritic_segments;
    public:
        MemoryCell();
        //
        void activate_directly();
        //
        std::string get_cell_visualization();
    };
}

#endif // MEMORYCELL_H
