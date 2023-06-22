#include "synapse.h"

using namespace model;

Synapse::Synapse()
{

}

Synapse::Synapse(double initial_permanent) : Synapse()
{
    permanent = initial_permanent;
}

std::string Synapse::get_synapse_visualization()
{
    switch (weight) {
    case BinaryWeight::ACTIVE:
        return "red";
    default:
        return "gray";
    }
}
