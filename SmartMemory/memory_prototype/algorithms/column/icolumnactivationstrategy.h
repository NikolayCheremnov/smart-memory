#ifndef ICOLUMNACTIVATIONSTRATEGY_H
#define ICOLUMNACTIVATIONSTRATEGY_H

#include <model/datatypes.h>
#include <model/corticalcolumn.h>


namespace algorithms {

    // IColumnActivationStrategy incapsulates strategy of column activation
    // that makes column_activation according
    // proximal dendritic segment state.
    class IColumnActivationStrategy
    {
    public:
        IColumnActivationStrategy();
        virtual ~IColumnActivationStrategy(){}
        virtual bool calculate_column_activation(model::CorticalColumnPtr column) = 0;
    };
}

#endif // ICOLUMNACTIVATIONSTRATEGY_H
