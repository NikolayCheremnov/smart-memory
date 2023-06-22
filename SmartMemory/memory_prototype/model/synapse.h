#ifndef SYNAPSE_H
#define SYNAPSE_H

#include "memorystructure.h"


namespace model {

    // Synapse is a link between columns or cells
    class Synapse :
            public MemoryStructure
    {
    // Synapse state enums
    public:
        enum class BinaryWeight {
            // modeling binary weight
            ACTIVE, // <=> 1
            SLEEP   // <=> 0
        };
    private:
        BinaryWeight weight;
        double permanent;
    public:
        Synapse();
        Synapse(double initial_permanent);

        // properties
        BinaryWeight& Weight() { return weight; }
        double& Permanent() { return permanent; }
        bool is_active() { return weight == BinaryWeight::ACTIVE; }

        //
        std::string get_synapse_visualization();
    };
}

#endif // SYNAPSE_H
