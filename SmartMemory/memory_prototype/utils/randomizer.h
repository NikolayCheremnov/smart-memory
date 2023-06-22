#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>


namespace utils {

    class Randomizer
    {
    public:
        Randomizer();

        //
        static double next_double(double min, double max);
        static int32_t next_int(int32_t min, int32_t max);
    };
}

#endif // RANDOMIZER_H
