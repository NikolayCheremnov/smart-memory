#ifndef DENDRITICSEGMENTFACTORY_H
#define DENDRITICSEGMENTFACTORY_H


#include <vector>

#include <model/datatypes.h>
#include <model/dendriticsegment.h>
#include <model/synapse.h>

namespace factory {

    class DendriticSegmentFactory
    {
    public:
        DendriticSegmentFactory();
        //
        static model::DendriticSegmentPtr make(std::vector<model::SynapsePtr> synapses);
    };
}

#endif // DENDRITICSEGMENTFACTORY_H
