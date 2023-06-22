#include "memorystructure.h"

using namespace model;

boost::uuids::random_generator MemoryStructure::generate_uuid;

MemoryStructure::MemoryStructure()
{
    uuid = generate_uuid();
}

std::string MemoryStructure::uuid_str()
{
    return boost::uuids::to_string(uuid);
}

std::string MemoryStructure::short_uuid_str()
{
    std::string uuid_s = uuid_str();
    return uuid_s.substr(uuid_s.size() - 5);    // TODO: 5 is magic constant, need move to config
}
