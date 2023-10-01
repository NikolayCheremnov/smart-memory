#ifndef ISENSOR_H
#define ISENSOR_H

#include "sensor.h"

#include <algorithms/input/input.h>
#include <algorithms/input/inputsignalbase.h>

#include <model/datatypes.h>
#include <model/memoryregion.h>

namespace algorithms {
    class ISensor
    {
    public:
        ISensor();
        virtual ~ISensor() {}
        // read_signal convert incomming signal to received impulses by memory region proximal synapses.
        // it returns IPulseDispatcher that can dispatch pulses to concrete synapses.
        virtual IPulseDispatcherPtr read_signal(InputSignalBasePtr signal, model::MemoryRegionPtr region) = 0;
    };
}

#endif // ISENSOR_H
