#include "dendriticsegment.h"

using namespace model;

DendriticSegment::DendriticSegment()
{

}

void DendriticSegment::add_synapse(SynapsePtr synapse)
{
    synapses.push_back(synapse);
}

size_t DendriticSegment::get_segment_size()
{
    return synapses.size();
}

SynapsePtr DendriticSegment::get_segment_synapse_by_index(size_t index)
{
    if (index >= 0 && index < synapses.size()) {
        return synapses[index];
    }
    return nullptr;
}
