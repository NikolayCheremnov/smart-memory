#include "dendriticsegmentfactory.h"

using namespace factory;

DendriticSegmentFactory::DendriticSegmentFactory()
{

}

model::DendriticSegmentPtr DendriticSegmentFactory::make(std::vector<model::SynapsePtr> synapses)
{
    model::DendriticSegment* segment = new model::DendriticSegment();
    for (const auto &synapse : synapses) {
        segment->add_synapse(synapse);
    }
    return model::DendriticSegmentPtr(segment);
}
