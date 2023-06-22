#ifndef DENDRITICSEGMENT_H
#define DENDRITICSEGMENT_H

#include <vector>

#include "datatypes.h"
#include "memorystructure.h"


namespace model {

    // DendriticSegment concentrates incoming connections in the form of synapses
    class DendriticSegment
            : public MemoryStructure
    {
    private:
        std::vector<SynapsePtr> synapses;

    public:
        DendriticSegment();
        //
        void add_synapse(SynapsePtr synapse);
        //
        size_t get_segment_size();
        SynapsePtr get_segment_synapse_by_index(size_t index);
    };
}

#endif // DENDRITICSEGMENT_H
