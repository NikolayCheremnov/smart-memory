#ifndef BYTEARRSIGNAL_H
#define BYTEARRSIGNAL_H

#include <string>
#include <sstream>
#include <memory.h>

#include "inputsignalbase.h"


namespace algorithms {

    class ByteArrSignal :
            public InputSignalBase
    {
    private:
        char* data;
        size_t data_size;   // size of data in bytes
    public:
        // constructors which read from buffer
        ByteArrSignal(const char * input_buffer, size_t size);
        ByteArrSignal(char* input_buffer, size_t size);
        //
        ~ByteArrSignal();
        // getters
        char* get_data() { return data; }
        size_t get_data_size() { return data_size; }
        // zeroing
        void reset_signal();
        bool is_zero_signal();
        // representations
        char* as_bytes(size_t& result_size) override;
        std::string to_std_string() override;
        char* to_bytes(size_t& result_size) override;
    };
}

#endif // BYTEARRSIGNAL_H
