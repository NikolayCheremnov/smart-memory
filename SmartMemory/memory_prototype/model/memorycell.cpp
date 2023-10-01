#include "memorycell.h"

using namespace model;

MemoryCell::MemoryCell()
{
    previous_state = state = ViewableState::PASSIVE; // default passive cell
}

void MemoryCell::activate_directly()
{
    change_state(ViewableState::FEED_FORWARD);
}

void MemoryCell::activate_side_feed()
{
    change_state(ViewableState::SIDE_FEED);
}

void MemoryCell::deactivate()
{
    change_state(ViewableState::PASSIVE);
}

void MemoryCell::change_state(ViewableState state)
{
    previous_state = state;
    this->state = state;
}

void MemoryCell::connect_cell(MemoryCellPtr source, DendriticSegmentPtr segment)
{
    distal_dendritic_segments[source.get()] = segment;
    source->connected_cells.push_back(MemoryCellPtr(this));

}

std::map<MemoryCell *, DendriticSegmentPtr> MemoryCell::get_distal_dendritic_segments()
{
    return distal_dendritic_segments;
}

bool MemoryCell::is_active_directly()
{
    return state == ViewableState::FEED_FORWARD;
}

bool MemoryCell::is_active_side_feed()
{
    return state == ViewableState::SIDE_FEED;
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
