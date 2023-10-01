#ifndef MAPPULSEDISPATCHER_H
#define MAPPULSEDISPATCHER_H

#include <map>

#include "ipulsedispatcher.h"

namespace algorithms {
    class MapPulseDispatcher :
            public IPulseDispatcher
    {
    private:
        std::map<std::string, bool> pulses;
    public:
        MapPulseDispatcher();

        void write_synapse_pulse(model::SynapsePtr synapse, bool pulse);
        //
        bool read_synapse_pulse(model::SynapsePtr synapse) override;
    };
}
#endif // MAPPULSEDISPATCHER_H
