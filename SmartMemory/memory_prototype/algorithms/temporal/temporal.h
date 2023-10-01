#ifndef TEMPORAL_H
#define TEMPORAL_H


#include <memory>

namespace algorithms {
    class ILateralCatalyst;
    class ILateralInhibitor;

    typedef std::shared_ptr<ILateralCatalyst> ILateralCatalystPtr;
    typedef std::shared_ptr<ILateralInhibitor> ILateralInhibitorPtr;
}

#endif // TEMPORAL_H
