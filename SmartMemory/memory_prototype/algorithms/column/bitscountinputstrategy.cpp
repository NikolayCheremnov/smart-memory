#include "bitscountinputstrategy.h"

using namespace algorithms;

BitsCountInputStrategy::BitsCountInputStrategy(double count_bits_delta_threshold)
    : count_bits_delta_threshold{count_bits_delta_threshold}
{

}

double BitsCountInputStrategy::input(model::CorticalColumnPtr column, InputSignalBase* signal)
{
    size_t signal_size;
    char* signal_bytes = signal->as_bytes(signal_size);
    size_t signal_count_bits = utils::BitHelper::count_bits(signal_bytes, signal_size);
    //
    size_t column_count_bits = 0;
    size_t column_height = column->get_column_height();
    for (size_t i = 0; i < column_height; i++) {
        column_count_bits += utils::BitHelper::count_bits(
                    column->get_column_cell_by_index(i)->short_uuid_str());
    }
    //
    double coincidence = abs((int)signal_count_bits - (int)column_count_bits) /
            (double)column_count_bits;
    if (coincidence <= count_bits_delta_threshold) {
        return 1.0;
    }
    return 0.0;
}
