#include "memoryregion.h"

using namespace model;

MemoryRegion::MemoryRegion()
{

}

void MemoryRegion::add_column(CorticalColumnPtr column)
{
    cortical_columns_set.push_back(column);
}

uint32_t MemoryRegion::get_cortical_columns_set_size()
{
    return cortical_columns_set.size();
}

CorticalColumnPtr MemoryRegion::get_cortical_column_by_index(uint32_t index)
{
    if (index >= 0 && index < cortical_columns_set.size()) {
        return cortical_columns_set[index];
    }
    return nullptr;
}
