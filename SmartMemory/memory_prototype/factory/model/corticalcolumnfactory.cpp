#include "corticalcolumnfactory.h"

using namespace factory;

CorticalColumnFactory::CorticalColumnFactory()
{

}

model::CorticalColumnPtr CorticalColumnFactory::make(size_t column_height, std::vector<model::SynapsePtr> proximal_synapses)
{
    // 1. add cells
    model::CorticalColumnPtr column = make(column_height);
    // 2. add proximal synapses (proximal dendritic segment)
    for (const auto &synapse : proximal_synapses) {
        column->add_proximal_synapse(synapse);
    }
    //
    return column;
}

model::CorticalColumnPtr CorticalColumnFactory::make(size_t column_height)
{
    model::CorticalColumn* column = new model::CorticalColumn(1.0, 1); // TODO: add parameters boost and radius
    for (size_t i = 0; i < column_height; i++) {
        auto cell = factory::MemoryCellFactory::make(model::MemoryCell::ViewableState::PASSIVE);
        column->add_cell(cell);
    }
    return model::CorticalColumnPtr(column);
}
