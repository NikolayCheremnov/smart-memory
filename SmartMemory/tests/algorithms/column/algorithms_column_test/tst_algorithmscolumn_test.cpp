#include <QtTest>

#include <vector>

#include <model/input/bytearrsignal.h>
#include <algorithms/column/bitscountinputstrategy.h>
#include <algorithms/column/icolumnactivationstrategy.h>
#include <algorithms/column/icolumninputstrategy.h>
#include <algorithms/column/percentagecolumnactivationstrategy.h>
#include <factory/model/synapsefactory.h>
#include <factory/model/corticalcolumnfactory.h>

class AlgorithmsColumn_Test : public QObject
{
    Q_OBJECT

public:
    AlgorithmsColumn_Test();
    ~AlgorithmsColumn_Test();

private slots:
    //
    void test_calculate_column_activation_PercentageColumnActivationStrategy();
    //
    void test_input_BitsCountInputStrategy();
};

AlgorithmsColumn_Test::AlgorithmsColumn_Test()
{

}

AlgorithmsColumn_Test::~AlgorithmsColumn_Test()
{

}

void AlgorithmsColumn_Test::test_calculate_column_activation_PercentageColumnActivationStrategy()
{
    algorithms::IColumnActivationStrategy* strategy = new algorithms::PercentageColumnActivationStrategy(50.0);
    //
    std::vector<model::SynapsePtr> proximal_synapses{
        factory::SynapseFactory::make(model::Synapse::BinaryWeight::ACTIVE, 1.0),
        factory::SynapseFactory::make(model::Synapse::BinaryWeight::ACTIVE, 1.0),
        factory::SynapseFactory::make(model::Synapse::BinaryWeight::ACTIVE, 1.0),
        factory::SynapseFactory::make(model::Synapse::BinaryWeight::SLEEP, 0.0),
        factory::SynapseFactory::make(model::Synapse::BinaryWeight::SLEEP, 0.0),
    };
    model::CorticalColumnPtr column = factory::CorticalColumnFactory::make(6, proximal_synapses);
    strategy->calculate_column_activation(column);
    QVERIFY(column->is_all_column_active());
    //
    proximal_synapses.push_back(factory::SynapseFactory::make(model::Synapse::BinaryWeight::SLEEP, 0.0));
    column = factory::CorticalColumnFactory::make(6, proximal_synapses);
    strategy->calculate_column_activation(column);
    QVERIFY(column->is_all_column_active());
    //
    proximal_synapses.push_back(factory::SynapseFactory::make(model::Synapse::BinaryWeight::SLEEP, 0.0));
    column = factory::CorticalColumnFactory::make(6, proximal_synapses);
    strategy->calculate_column_activation(column);
    QVERIFY(!column->is_all_column_active());
    //
    delete strategy;
}

void AlgorithmsColumn_Test::test_input_BitsCountInputStrategy()
{
    algorithms::IColumnInputStrategy* strategy = new algorithms::BitsCountInputStrategy(0.1);
    //
    model::CorticalColumnPtr column = factory::CorticalColumnFactory::make(4);
    std::string column_signal = "";
    for (size_t i = 0; i < column->get_column_height(); i++) {
        column_signal += column->get_column_cell_by_index(i)->short_uuid_str();
    }
    model::InputSignalBasePtr signal(new model::ByteArrSignal(column_signal.c_str(), column_signal.length()));
    double actual_input = strategy->input(column, signal);
    QCOMPARE(actual_input, 1.0);
    //
    // TODO: write this test
    //signal.reset()
    delete strategy;
}

QTEST_APPLESS_MAIN(AlgorithmsColumn_Test)

#include "tst_algorithmscolumn_test.moc"
