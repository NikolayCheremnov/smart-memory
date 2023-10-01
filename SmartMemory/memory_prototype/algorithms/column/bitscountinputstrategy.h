#ifndef BITSCOUNTINPUTSTRATEGY_H
#define BITSCOUNTINPUTSTRATEGY_H

#include "icolumninputstrategy.h"

#include <utils/bithelper.h>

namespace algorithms {

    // BitsCountInputStrategy implements input strategy and
    // calculates input weight
    // via calculating the percentage correlation of the signal bits and the column
    // with precision count_bits_delta_threshold.
    class BitsCountInputStrategy :
            public IColumnInputStrategy
    {
    private:
        double count_bits_delta_threshold; // 0.1 <=> 10% of difference
    public:
        BitsCountInputStrategy(double count_bits_delta_threshold=0.1);
        double input(model::CorticalColumnPtr column, InputSignalBase* signal) override;
    };
}

#endif // BITSCOUNTINPUTSTRATEGY_H
