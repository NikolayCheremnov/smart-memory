#ifndef MEMORYCELLFACTORY_H
#define MEMORYCELLFACTORY_H

#include <model/datatypes.h>
#include <model/memorycell.h>

namespace factory {

    class MemoryCellFactory
    {
    public:
        MemoryCellFactory();
        //
        static model::MemoryCellPtr make(model::MemoryCell::ViewableState state);
    };
}

#endif // MEMORYCELLFACTORY_H
