#ifndef IPULSEDISPATCHER_H
#define IPULSEDISPATCHER_H

#include <model/datatypes.h>
#include <model/synapse.h>

namespace algorithms {

    class IPulseDispatcher
    {
    public:
        IPulseDispatcher();
        virtual ~IPulseDispatcher() {}

        //
        virtual bool read_synapse_pulse(model::SynapsePtr synapse) = 0;
    };
}
#endif // IPULSEDISPATCHER_H
