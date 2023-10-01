#ifndef MEMORYREGIONFACTORY_H
#define MEMORYREGIONFACTORY_H

#include <model/datatypes.h>
#include <model/memoryregion.h>

#include "corticalcolumnfactory.h"

namespace factory {
    class MemoryRegionFactory
    {
    public:
        MemoryRegionFactory();

        static model::MemoryRegionPtr make(size_t cortical_columns_count, size_t cortical_column_height);
    };
}

#endif // MEMORYREGIONFACTORY_H
