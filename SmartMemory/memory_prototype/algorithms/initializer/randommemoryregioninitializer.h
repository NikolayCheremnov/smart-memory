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

#include <algorithms/spatial/ispatialviewsrategy.h>

#include <algorithms/cell/icellsidefeedactivationstrategy.h>

#include <algorithms/temporal/irecognitionstrategy.h>

#include <factory/model/dendriticsegmentfactory.h>


namespace algorithms {

    class RandomMemoryRegionInitializer
    {
    public:
        struct SynapsesInitializerArgs {
            // proximal synapses args
            size_t min_proximal_synapses;
            size_t max_proximal_synapses;
            double min_proximal_permanent;
            double max_proximal_permanent;
            // distal synapses args
            size_t min_distal_synapses;
            size_t max_distal_synapses;
            double min_distal_permanent;
            double max_distal_permanent;
        };
    public:
        RandomMemoryRegionInitializer();
        //
        void initialize_memory_region(
                model::MemoryRegionPtr region,
                SynapsesInitializerArgs args,
                size_t distal_radius,
                ISynapseActivationStrategy* synapse_activation_strategy,
                ISpatialViewSrategy* spatial_view_strategy,
                IColumnActivationStrategy* column_activation_strategy,
                IRecognitionStrategy* recognition_strategy,
                ICellSideFeedActivationStrategy* cell_side_feed_activation_strategy
        );

    private:
        // help methods
        void initialize_proximal_synapses(
                model::CorticalColumnPtr column,
                SynapsesInitializerArgs args,
                ISynapseActivationStrategy* synapse_activation_strategy
        );

        void initialize_distal_synapses(
                model::MemoryRegionPtr region,
                SynapsesInitializerArgs args,
                size_t distal_radius,
                ISynapseActivationStrategy* synapse_activation_strategy,
                ISpatialViewSrategy* spatial_view_strategy,
                ICellSideFeedActivationStrategy* cell_side_feed_activation_strategy
        );
    };
}

#endif // RANDOMMEMORYREGIONINITIALIZER_H
