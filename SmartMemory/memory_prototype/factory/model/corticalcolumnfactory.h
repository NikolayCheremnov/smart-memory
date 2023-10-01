#ifndef CORTICALCOLUMNFACTORY_H
#define CORTICALCOLUMNFACTORY_H


#include <vector>

#include <model/datatypes.h>
#include <model/corticalcolumn.h>

#include <factory/model/memorycellfactory.h>

namespace factory {

    class CorticalColumnFactory
    {
    public:
        CorticalColumnFactory();
        //
        static model::CorticalColumnPtr make(size_t column_height, std::vector<model::SynapsePtr> proximal_synapses);
        static model::CorticalColumnPtr make(size_t column_height);
    };
}

#endif // CORTICALCOLUMNFACTORY_H
