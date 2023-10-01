#ifndef ISEGMENTACTIVATIONSTRATEGY_H
#define ISEGMENTACTIVATIONSTRATEGY_H


#include <model/datatypes.h>
#include <model/dendriticsegment.h>
#include <model/synapse.h>

namespace algorithms {
    class ISegmentActivationStrategy
    {
    public:
        ISegmentActivationStrategy();
        virtual ~ISegmentActivationStrategy() {}

        //
        virtual bool is_dendritic_segment_active(model::DendriticSegmentPtr segment) = 0;
    };
}

#endif // ISEGMENTACTIVATIONSTRATEGY_H
