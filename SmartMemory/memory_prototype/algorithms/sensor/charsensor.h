#ifndef CHARSENSOR_H
#define CHARSENSOR_H

#include "isensor.h"

#include "mappulsedispatcher.h"

#include <model/corticalcolumn.h>

#include <utils/bithelper.h>

namespace algorithms {

    // CharSensor read signal as char ASCII-code
    // bits are distributed by synapses
    class CharSensor
            : public ISensor
    {
    public:
        CharSensor();

        //
        IPulseDispatcherPtr read_signal(InputSignalBasePtr signal, model::MemoryRegionPtr region) override;
    };
}

#endif // CHARSENSOR_H
