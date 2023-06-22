#ifndef MEMORYREGION_H
#define MEMORYREGION_H

#include <vector>

#include "datatypes.h"
#include "memorystructure.h"


namespace model {

    // MemoryRegion is the class of HTM memory region
    class MemoryRegion
            : public MemoryStructure
    {
    private:
        std::vector<CorticalColumnPtr> cortical_columns_set;
    public:
        MemoryRegion();

        //
        void add_column(CorticalColumnPtr column);
        uint32_t get_cortical_columns_set_size();
        CorticalColumnPtr get_cortical_column_by_index(uint32_t index);
    };
}

#endif // MEMORYREGION_H
