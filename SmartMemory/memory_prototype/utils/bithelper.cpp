#include "bithelper.h"

using namespace utils;

BitHelper::BitHelper()
{

}

size_t BitHelper::count_bits(char *arr, size_t size)
{
    size_t count = 0;
    for (size_t i = 0; i < size; i++) {
        unsigned char mask = 1;
        for (size_t j = 0; j < 8; j++) {
            if (arr[i] & (mask << j))
                count++;
        }
    }
    return count;
}

size_t BitHelper::count_bits(std::string std_str)
{
    return count_bits((char*)std_str.c_str(), std_str.length());
}

char *BitHelper::bits2bytes(char *bits_c_str, size_t& result_size)
{
    if (!verify_bits_string(bits_c_str)) {
        return nullptr;
    }
    size_t received_bits_count = strlen(bits_c_str);
    size_t bytes_count = received_bits_count / 8;
    size_t non_significant_bits_count = 0;
    if (received_bits_count % 8 != 0) {
        bytes_count++;
        non_significant_bits_count = 8 - received_bits_count % 8;
    }
    char* bytes = new char[bytes_count];
    // write each byte
    size_t pos = 0;
    for (size_t i = 0; i < bytes_count; i++) {
        for (size_t j = 7; j < 8; j--) {
            if (non_significant_bits_count > 0) {
                bytes[i] = set_bit(bytes[i], j, '0');
                non_significant_bits_count--;
            } else {
                bytes[i] = set_bit(bytes[i], j, bits_c_str[pos++]);
            }
        }
    }
    result_size = bytes_count;
    return bytes;
}

char *BitHelper::bits2bytes(const char *bits_c_str, size_t &result_size)
{
    return bits2bytes((char*)bits_c_str, result_size);
}

bool BitHelper::verify_bits_string(char *bits_c_str)
{
    size_t len = strlen(bits_c_str);
    for (size_t i = 0; i < len; i++) {
        if (bits_c_str[i] != '0' && bits_c_str[i] != '1') {
            return false;
        }
    }
    return true;
}

bool BitHelper::verify_bits_string(const char *bits_const_c_str)
{
    return verify_bits_string((char*)bits_const_c_str);
}

bool BitHelper::verify_bits_string(std::string bits_std_str)
{
    return verify_bits_string(bits_std_str.c_str());
}

char BitHelper::set_bit(char byte, size_t pos, int16_t bit)
{
    if (bit == 0) {
        byte &= ~(1 << pos);
    }
    if (bit == 1) {
        byte |= (1 << pos);
    }
    return byte;
}

char BitHelper::set_bit(char byte, size_t pos, char bit)
{
    if (bit == '1') {
        return set_bit(byte, pos, (int16_t)1);
    }
    if (bit == '0') {
        return set_bit(byte, pos, (int16_t)0);
    }
    return byte;
}

bool BitHelper::check_bit(char byte, size_t pos)
{
    return byte & (1 << pos);
}
