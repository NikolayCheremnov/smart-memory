#ifndef SYNAPSEFACTORY_H
#define SYNAPSEFACTORY_H


#include <model/datatypes.h>
#include <model/synapse.h>

namespace factory {

    class SynapseFactory
    {
    public:
        SynapseFactory();
        //
        static model::SynapsePtr make(model::Synapse::BinaryWeight weight, double permanent);
    };
}
#endif // SYNAPSEFACTORY_H
