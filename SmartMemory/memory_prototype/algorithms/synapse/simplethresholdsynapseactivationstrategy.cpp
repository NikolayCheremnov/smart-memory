#include "simplethresholdsynapseactivationstrategy.h"


using namespace algorithms;

SimpleThresholdSynapseActivationStrategy::SimpleThresholdSynapseActivationStrategy(double threshold) :
    threshold{threshold}
{

}

void SimpleThresholdSynapseActivationStrategy::calculate_synapse_activation(model::SynapsePtr synapse)
{
    if (synapse->Permanent() >= threshold) {
        synapse->Weight() = model::Synapse::BinaryWeight::ACTIVE;
    } else {
        synapse->Weight() = model::Synapse::BinaryWeight::SLEEP;
    }
}
