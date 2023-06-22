#ifndef RANDOMMEMORYREGIONINITIALIZER_H
#define RANDOMMEMORYREGIONINITIALIZER_H

#include <model/datatypes.h>
#include <model/memoryregion.h>
#include <model/corticalcolumn.h>
#include <model/memorycell.h>
#include <model/synapse.h>

#include <utils/randomizer.h>

#include <algorithms/synapse/isynapseactivationstrategy.h>

#include <algorithms/column/icolumnactivationstrategy.h>


namespace algorithms {

    class RandomMemoryRegionInitializer
    {
    public:
        struct RandomMemoryRegionInitializerArgs {
            size_t min_column_proximal_synapses;
            size_t max_column_proximal_synapses;
            double min_proximal_permanent;
            double max_proximal_permanent;

        };
    public:
        RandomMemoryRegionInitializer();
        //
        model::MemoryRegionPtr InitializeMemoryRegion(size_t cortical_columns_count,
                                                      size_t cortical_column_height,
                                                      RandomMemoryRegionInitializerArgs args,
                                                      ISynapseActivationStrategy* synapse_activation_strategy,
                                                      IColumnActivationStrategy* column_activation_strategy);
        model::MemoryRegionPtr InitializeEmptyMemoryRegion(size_t cortical_columns_count,
                                                           size_t cortical_column_height);
    };
}

#endif // RANDOMMEMORYREGIONINITIALIZER_H
