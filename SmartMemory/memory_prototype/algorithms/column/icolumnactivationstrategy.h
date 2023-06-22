#ifndef ICOLUMNACTIVATIONSTRATEGY_H
#define ICOLUMNACTIVATIONSTRATEGY_H

#include <model/datatypes.h>
#include <model/corticalcolumn.h>


namespace algorithms {
    class IColumnActivationStrategy
    {
    public:
        IColumnActivationStrategy();
        //
        virtual void calculate_column_activation(model::CorticalColumnPtr column) = 0;
    };
}

#endif // ICOLUMNACTIVATIONSTRATEGY_H
