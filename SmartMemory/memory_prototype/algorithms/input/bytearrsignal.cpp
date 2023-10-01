#include "bytearrsignal.h"

using namespace algorithms;

ByteArrSignal::ByteArrSignal(const char * input_buffer, size_t size) :
    ByteArrSignal((char*) input_buffer, size)
{

}

ByteArrSignal::ByteArrSignal(char *input_buffer, size_t size)
{
    if (input_buffer == nullptr || size == 0) {
        reset_signal();
    } else {
        data = new char[size];
        data_size = size;
        memcpy_s(data, size, input_buffer, size);
    }
}

ByteArrSignal::~ByteArrSignal()
{
    delete[] data;
}

std::string ByteArrSignal::to_std_string()
{
    if (is_zero_signal()) {
        return std::string();
    }
    std::ostringstream out;
    for (size_t i = 0; i < data_size; i++) {
        out << data[i];
    }
    return out.str();
}

char *ByteArrSignal::to_bytes(size_t &result_size)
{
    if (is_zero_signal()) {
        result_size = 0;
        return nullptr;
    }
    result_size = data_size;
    char* result = new char[result_size];
    memcpy_s(result, result_size, data, data_size);
    return result;
}

void ByteArrSignal::reset_signal()
{
    delete[] data;
    data = nullptr;
    data_size = 0;
}

bool ByteArrSignal::is_zero_signal()
{
    return data == nullptr;
}

char *ByteArrSignal::as_bytes(size_t& result_size)
{
    if (is_zero_signal()) {
        result_size = 0;
        return nullptr;
    }
    result_size = data_size;
    return data;
}
