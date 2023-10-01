#ifndef INPUT_H
#define INPUT_H

#include <memory>

namespace algorithms {
    class InputSignalBase;

    typedef std::shared_ptr<InputSignalBase> InputSignalBasePtr;
}

#endif // INPUT_H
