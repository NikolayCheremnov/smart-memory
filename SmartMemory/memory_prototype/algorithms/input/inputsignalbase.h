#ifndef INPUTSIGNALBASE_H
#define INPUTSIGNALBASE_H

#include <string>


namespace algorithms {

    class InputSignalBase
    {
    public:
        InputSignalBase();
        virtual ~InputSignalBase(){}

        // representations:
        // 1) without deep copy
        virtual char* as_bytes(size_t& result_size) = 0;
        // 2) with deep copy
        virtual char* to_bytes(size_t& result_size) = 0;
        virtual std::string to_std_string() = 0;
    };
}

#endif // INPUTSIGNALBASE_H
