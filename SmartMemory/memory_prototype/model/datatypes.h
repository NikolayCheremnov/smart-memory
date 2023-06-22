#ifndef DATATYPES_H
#define DATATYPES_H

#include <memory>

namespace model {
    // classes definitions
    class MemoryRegion;
    class CorticalColumn;
    class Synapse;
    class DendriticSegment;
    class MemoryCell;

    // shared ptr
    typedef std::shared_ptr<MemoryRegion> MemoryRegionPtr;
    typedef std::shared_ptr<CorticalColumn> CorticalColumnPtr;
    typedef std::shared_ptr<Synapse> SynapsePtr;
    typedef std::shared_ptr<DendriticSegment> DendriticSegmentPtr;
    typedef std::shared_ptr<MemoryCell> MemoryCellPtr;
}

#endif // DATATYPES_H
