#ifndef STANDARDLEARNINGSTRATEGY_H
#define STANDARDLEARNINGSTRATEGY_H


#include "ilearningstrategy.h"

#include <model/corticalcolumn.h>
#include <model/synapse.h>

namespace algorithms {
    class StandardLearningStrategy :
            public ILearningStrategy
    {
    private:
        double permanence_inc;
        double permanence_dec;
        double max_permanent;
        double min_permanent;
        double activity_factor;
        double boost_factor;
        double proximal_synapses_permanent_factor;
    public:
        StandardLearningStrategy(
                double permanence_inc,
                double permanence_dec,
                double max_permanent,
                double min_permanent,
                double activity_factor,
                double boost_factor,
                double proximal_synapses_permanent_factor
        );

        void make_learning(
                model::MemoryRegionPtr region,
                std::map<std::string, bool> column_activation_map
        ) override;
    };
}

#endif // STANDARDLEARNINGSTRATEGY_H
