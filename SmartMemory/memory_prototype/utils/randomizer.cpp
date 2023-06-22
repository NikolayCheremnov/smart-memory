#include "randomizer.h"

using namespace utils;

Randomizer::Randomizer()
{

}

double Randomizer::next_double(double min, double max)
{
    static std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(min, max);
    return dist(gen);
}

int32_t Randomizer::next_int(int32_t min, int32_t max)
{
    static std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}
