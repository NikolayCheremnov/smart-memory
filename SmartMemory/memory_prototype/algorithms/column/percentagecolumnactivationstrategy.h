#ifndef PERCENTAGECOLUMNACTIVATIONSTRATEGY_H
#define PERCENTAGECOLUMNACTIVATIONSTRATEGY_H

#include "icolumnactivationstrategy.h"

#include <model/synapse.h>

namespace algorithms {

    // PercentageColumnActivationStrategy using
    // percentage of active synapses in proximal dendritic segment to activate the column.
    // It makes column activation if percentage >= threshold.
    class PercentageColumnActivationStrategy
            : public IColumnActivationStrategy
    {
    private:
        double threshold;   // from 0% to 100% (can use other values, but it *100 yet)

    public:
        PercentageColumnActivationStrategy(double threshold);
        bool calculate_column_activation(model::CorticalColumnPtr column) override;
    };
}

#endif // PERCENTAGECOLUMNACTIVATIONSTRATEGY_H
