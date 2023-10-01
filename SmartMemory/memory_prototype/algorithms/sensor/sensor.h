#ifndef SENSOR_H
#define SENSOR_H

#include <memory>

namespace algorithms {
    class IPulseDispatcher;

    typedef std::shared_ptr<IPulseDispatcher> IPulseDispatcherPtr;
}

#endif // SENSOR_H
