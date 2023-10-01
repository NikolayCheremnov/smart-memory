#include "charsensor.h"

using namespace algorithms;

CharSensor::CharSensor()
{

}

IPulseDispatcherPtr CharSensor::read_signal(InputSignalBasePtr signal, model::MemoryRegionPtr region)
{
    // 0. check signals conditions
    size_t signal_size;
    char* signal_data = signal->as_bytes(signal_size);  // delete not needed
    if (signal_size > 1) {
        throw std::string("the signal is too long for this sensor");
    }
    // 1. check memory region conditions
    size_t columns_count = region->get_cortical_columns_set_size();
    if (columns_count < 8) {
        throw std::string("there are too few columns in the region");
    }
    for (size_t i = 0; i < columns_count; i++) {
        if (region->get_cortical_column_by_index(i)->get_proximal_dendritic_segment()->get_segment_size() < 1) {
            throw std::string("there are too few synapses in the proximal synapse in cortical column");
        }
    }
    // use map dispatcher
    MapPulseDispatcher* dispatcher = new MapPulseDispatcher();
    char read_signal = signal_size == 0? 0 : signal_data[0];
    for (size_t i = 0; i < 8; i++) {
        auto column = region->get_cortical_column_by_index(i);
        auto synapse = column->get_proximal_dendritic_segment()->get_segment_synapse_by_index(0);
        dispatcher->write_synapse_pulse(synapse, utils::BitHelper::check_bit(read_signal, i));
    }
    //
    return IPulseDispatcherPtr(dispatcher);
}
