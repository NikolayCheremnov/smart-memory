#include "mappulsedispatcher.h"

using namespace algorithms;

MapPulseDispatcher::MapPulseDispatcher()
{

}

void MapPulseDispatcher::write_synapse_pulse(model::SynapsePtr synapse, bool pulse)
{
    pulses[synapse->uuid_str()] = pulse;
}

bool MapPulseDispatcher::read_synapse_pulse(model::SynapsePtr synapse)
{
    // if synapse not in map, then return false
    std::string key = synapse->uuid_str();
    if (pulses.count(key)) {
        return pulses[key];
    }
    return false;
}
