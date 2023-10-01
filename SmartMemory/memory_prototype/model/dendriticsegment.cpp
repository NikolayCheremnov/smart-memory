#include "dendriticsegment.h"

using namespace model;

DendriticSegment::DendriticSegment()
{

}

void DendriticSegment::add_synapse(SynapsePtr synapse)
{
    synapses.push_back(synapse);
}

void DendriticSegment::remove_synapse_by_index(size_t index)
{
    synapses.erase(synapses.begin() + index);
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

void DendriticSegment::clear()
{
    synapses.clear();
}

double DendriticSegment::get_average_synapses_peermanent()
{
    size_t size = synapses.size();
    if (size == 0) {
        return 0;
    }
    double sum = 0.0;
    for (auto synapse : synapses) {
        sum += synapse->Permanent();
    }
    return sum / size;
}
