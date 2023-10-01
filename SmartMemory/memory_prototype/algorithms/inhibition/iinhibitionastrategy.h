#ifndef IINHIBITIONASTRATEGY_H
#define IINHIBITIONASTRATEGY_H


#include <map>

#include <model/datatypes.h>
#include <model/memoryregion.h>
#include <model/corticalcolumn.h>

namespace algorithms {

    class IInhibitionaStrategy
    {
    public:
        IInhibitionaStrategy();
        virtual ~IInhibitionaStrategy() {}

        //
        virtual std::map<std::string, bool> process_column_inhibition(model::MemoryRegionPtr region, std::map<std::string, double> overlap) = 0;

    };
}

#endif // IINHIBITIONASTRATEGY_H
