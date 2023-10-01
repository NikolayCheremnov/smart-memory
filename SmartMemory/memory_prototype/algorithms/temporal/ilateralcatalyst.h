#ifndef ILATERALCATALYST_H
#define ILATERALCATALYST_H


#include <model/datatypes.h>
#include <model/memorycell.h>
#include <model/dendriticsegment.h>

namespace algorithms {
    class ILateralCatalyst
    {
    public:
        ILateralCatalyst();
        virtual ~ILateralCatalyst() {}

        virtual void catalyze_lateral_synapses(model::MemoryCellPtr cell) = 0;
    };
}

#endif // ILATERALCATALYST_H
