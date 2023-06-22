#ifndef SIMPLEPERCENTAGECOLUMNACTIVATIONSTRATEGY_H
#define SIMPLEPERCENTAGECOLUMNACTIVATIONSTRATEGY_H

#include "icolumnactivationstrategy.h"

#include <model/synapse.h>

namespace algorithms {

    class SimplePercentageColumnActivationStrategy
            : public IColumnActivationStrategy
    {
    private:
        double threshold;

    public:
        SimplePercentageColumnActivationStrategy(double threshold);
        //
        void calculate_column_activation(model::CorticalColumnPtr column) override;
    };
}

#endif // SIMPLEPERCENTAGECOLUMNACTIVATIONSTRATEGY_H
