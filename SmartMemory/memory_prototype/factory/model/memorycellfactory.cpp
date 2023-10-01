#include "memorycellfactory.h"

using namespace factory;

MemoryCellFactory::MemoryCellFactory()
{

}

model::MemoryCellPtr MemoryCellFactory::make(model::MemoryCell::ViewableState state)
{
    model::MemoryCell* cell = new model::MemoryCell();
    cell->change_state(state);
    return model::MemoryCellPtr(cell);
}
