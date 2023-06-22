#ifndef MEMORYSTRUCTURE_H
#define MEMORYSTRUCTURE_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>


namespace model {

    // Base class for memory module structures
    class MemoryStructure
    {
    private:
        static boost::uuids::random_generator generate_uuid;    // uuid generator for memory structures
    protected:
        boost::uuids::uuid uuid;

    public:
        MemoryStructure();

        // getters & setters
        std::string uuid_str();
        std::string short_uuid_str();
    };
}

#endif // MEMORYSTRUCTURE_H
