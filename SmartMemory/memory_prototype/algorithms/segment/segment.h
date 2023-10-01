#ifndef SEGMENT_H
#define SEGMENT_H

#include <memory>

namespace algorithms {
    class ISegmentActivationStrategy;

    typedef std::shared_ptr<ISegmentActivationStrategy> ISegmentActivationStrategyPtr;
}

#endif // SEGMENT_H
