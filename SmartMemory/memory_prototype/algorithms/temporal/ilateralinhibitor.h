#ifndef ILATERALINHIBITOR_H
#define ILATERALINHIBITOR_H


#include <model/datatypes.h>
#include <model/memorycell.h>
#include <model/dendriticsegment.h>

namespace algorithms {
    class ILateralInhibitor
    {
    public:
        ILateralInhibitor();
        virtual ~ILateralInhibitor() {}

        //
        virtual void inhibite_lateral_synapses(model::MemoryCellPtr cell) = 0;
    };
}

#endif // ILATERALINHIBITOR_H
