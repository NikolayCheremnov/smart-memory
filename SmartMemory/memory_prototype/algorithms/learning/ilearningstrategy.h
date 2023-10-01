#ifndef ILEARNINGSTRATEGY_H
#define ILEARNINGSTRATEGY_H


#include <map>

#include <model/datatypes.h>
#include <model/memoryregion.h>

#include <algorithms/synapse/isynapseactivationstrategy.h>

namespace algorithms {
    class ILearningStrategy
    {
    public:
        ILearningStrategy();
        virtual ~ILearningStrategy() {}

        //
        virtual void make_learning(
                model::MemoryRegionPtr region,
                std::map<std::string, bool> column_activation_map
        ) = 0;
    };
}

#endif // ILEARNINGSTRATEGY_H
