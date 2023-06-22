#include <QCoreApplication>

#include <iostream>

#include <model/datatypes.h>
#include <model/synapse.h>

#include <algorithms/randommemoryregioninitializer.h>
#include <algorithms/synapse/simplethresholdsynapseactivationstrategy.h>
#include <algorithms/column/simplepercentagecolumnactivationstrategy.h>

#include <graph_utils/dotgenerator.h>

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    // model::SynapsePtr t = model::SynapsePtr(new model::Synapse());
    // std::cout << t->uuid_str() << std::endl;

    // 1.
    algorithms::ISynapseActivationStrategy* ss = new algorithms::SimpleThresholdSynapseActivationStrategy(1.0);
    algorithms::IColumnActivationStrategy* cs = new algorithms::SimplePercentageColumnActivationStrategy(50);
    algorithms::RandomMemoryRegionInitializer::RandomMemoryRegionInitializerArgs args{5, 5, 0.7, 1.3};
    algorithms::RandomMemoryRegionInitializer r;
    model::MemoryRegionPtr region = r.InitializeMemoryRegion(3, 4, args, ss, cs);
    // 2.
    gu::DotGenerator g;
    std::string out = g.GenerateCellularMemoryFrameAsDot(region);
    // 3.
    std::cout << out << std::endl;
    //return a.exec();
}
