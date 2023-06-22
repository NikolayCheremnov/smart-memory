#ifndef SIMPLETHRESHOLDSYNAPSEACTIVATIONSTRATEGY_H
#define SIMPLETHRESHOLDSYNAPSEACTIVATIONSTRATEGY_H

#include "isynapseactivationstrategy.h"


namespace algorithms {

    class SimpleThresholdSynapseActivationStrategy
            : public ISynapseActivationStrategy
    {
    private:
        double threshold;
    public:
        SimpleThresholdSynapseActivationStrategy(double threshold);
        void calculate_synapse_activation(model::SynapsePtr synapse) override;
    };
}

#endif // SIMPLETHRESHOLDSYNAPSEACTIVATIONSTRATEGY_H
