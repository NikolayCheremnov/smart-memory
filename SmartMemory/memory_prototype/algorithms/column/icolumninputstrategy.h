#ifndef ICOLUMNINPUTSTRATEGY_H
#define ICOLUMNINPUTSTRATEGY_H

#include <model/datatypes.h>
#include <model/corticalcolumn.h>
#include <algorithms/input/inputsignalbase.h>

namespace algorithms {

    // IColumnInputStrategy incapsulates strategy of input activation between
    // signal from synapse (just signal) and column.
    // Input work as a function and returns double value as input weight.
    class IColumnInputStrategy
    {
    public:
        IColumnInputStrategy();
        virtual ~IColumnInputStrategy(){}
        virtual double input(model::CorticalColumnPtr column, InputSignalBase* signal) = 0;
    };
}

#endif // ICOLUMNINPUTSTRATEGY_H
