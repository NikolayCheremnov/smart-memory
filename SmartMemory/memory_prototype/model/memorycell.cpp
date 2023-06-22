#include "memorycell.h"

using namespace model;

MemoryCell::MemoryCell()
{
    state = ViewableState::PASSIVE; // default passive cell
}

void MemoryCell::activate_directly()
{
    state = ViewableState::FEED_FORWARD;
}

std::string MemoryCell::get_cell_visualization()
{
    switch(state) {
    case ViewableState::FEED_FORWARD:
        return "#DDDDDD";
    case ViewableState::SIDE_FEED:
        return "#DDDFFF";
    default:
        return "#FFFFFF";
    }
}
