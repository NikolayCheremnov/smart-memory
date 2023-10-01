#include "synapsefactory.h"

using namespace factory;

SynapseFactory::SynapseFactory()
{

}

model::SynapsePtr SynapseFactory::make(model::Synapse::BinaryWeight weight, double permanent)
{
    model::Synapse* synapse = new model::Synapse(permanent);
    synapse->Weight() = weight;
    return model::SynapsePtr(synapse);
}
