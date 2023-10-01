#ifndef ISYNAPSEACTIVATIONSTRATEGY_H
#define ISYNAPSEACTIVATIONSTRATEGY_H

#include <model/datatypes.h>
#include <model/synapse.h>



namespace algorithms {

    class ISynapseActivationStrategy
    {
    public:
        ISynapseActivationStrategy();
        virtual ~ISynapseActivationStrategy(){}
        //
        virtual void calculate_synapse_activation(model::SynapsePtr synapse) = 0;
    };
}
#endif // ISYNAPSEACTIVATIONSTRATEGY_H
