#ifndef DENDRITICSEGMENT_H
#define DENDRITICSEGMENT_H

#include <vector>

#include "datatypes.h"
#include "memorystructure.h"
#include "synapse.h"


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
        void remove_synapse_by_index(size_t index);
        //
        size_t get_segment_size();
        SynapsePtr get_segment_synapse_by_index(size_t index);
        //
        void clear();
        double get_average_synapses_peermanent();
    };
}

#endif // DENDRITICSEGMENT_H
