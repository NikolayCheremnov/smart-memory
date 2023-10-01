#ifndef BITHELPER_H
#define BITHELPER_H

#include <stdlib.h>
#include <cstring>
#include <string>

namespace utils {

    class BitHelper
    {
    public:
        BitHelper();
        // count_bits calculates number of bits in byte array (not c-string)
        static size_t count_bits(char* arr, size_t size);
        static size_t count_bits(std::string std_str);
        //
        static char* bits2bytes(char* bits_c_str, size_t& result_size);
        static char* bits2bytes(const char* bits_c_str, size_t& result_size);
        // verify_bits_string checks correctness of bits in string representation like a "111010"
        // "1010100101110" - ok
        // "1234" - not ok
        static bool verify_bits_string(char* bits_c_str);
        static bool verify_bits_string(const char* bits_const_c_str);
        static bool verify_bits_string(std::string bits_std_str);
        // bits setters
        static char set_bit(char byte, size_t pos, int16_t bit);
        static char set_bit(char byte, size_t pos, char bit);
        // bits getters
        static bool check_bit(char byte, size_t pos);
    };
}

#endif // BITHELPER_H
