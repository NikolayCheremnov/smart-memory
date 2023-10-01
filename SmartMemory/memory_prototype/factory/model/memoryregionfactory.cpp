#include "memoryregionfactory.h"

using namespace factory;

MemoryRegionFactory::MemoryRegionFactory()
{

}

model::MemoryRegionPtr MemoryRegionFactory::make(size_t cortical_columns_count, size_t cortical_column_height)
{
    model::MemoryRegionPtr memory_region = model::MemoryRegionPtr(new model::MemoryRegion());
    // initialize and add columns
    for (uint32_t i = 0; i < cortical_columns_count; i++) {
        model::CorticalColumnPtr column = CorticalColumnFactory::make(cortical_column_height);
        memory_region->add_column(column);
    }
    return memory_region;
}
