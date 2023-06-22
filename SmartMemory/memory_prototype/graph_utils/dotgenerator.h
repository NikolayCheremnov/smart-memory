#ifndef DOTGENERATOR_H
#define DOTGENERATOR_H

#include <iostream>
#include <sstream>

#include <model/datatypes.h>
#include <model/memoryregion.h>
#include <model/corticalcolumn.h>
#include <model/synapse.h>


namespace gu {

    class DotGenerator
    {
    public:
        DotGenerator();

        //
        std::string GenerateCellularMemoryFrameAsDot(model::MemoryRegionPtr memory_region);
        // help methods
        std::string column_cells_as_dot(model::CorticalColumnPtr column, size_t column_index);
        std::string column_proximal_synapses_as_dot(model::CorticalColumnPtr column, std::string input_label);
    };
}

#endif // DOTGENERATOR_H
