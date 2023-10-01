#include <QtTest>

#include <string>

#include <../../../../memory_prototype/algorithms/input/bytearrsignal.h>

class ByteArrSignal_Test : public QObject
{
    Q_OBJECT

public:
    ByteArrSignal_Test();
    ~ByteArrSignal_Test();

private slots:
    // ByteArrSignal test cases
    void test_to_std_string_ByteArrSignal();
    void test_to_bytes_ByteArrSignal();
    void test_as_bytes_ByteArrSignal();
};

ByteArrSignal_Test::ByteArrSignal_Test()
{

}

ByteArrSignal_Test::~ByteArrSignal_Test()
{

}

void ByteArrSignal_Test::test_to_std_string_ByteArrSignal()
{
    //
    std::string expected = "hello";
    algorithms::InputSignalBase* signal = new algorithms::ByteArrSignal(expected.c_str(), expected.length());
    std::string actual = signal->to_std_string();
    QCOMPARE(QString(actual.c_str()), QString(expected.c_str()));
    //
    const char* input_buf = "hello";
    expected = "hell";
    delete signal;
    signal = new algorithms::ByteArrSignal(input_buf, expected.length());
    actual = signal->to_std_string();
    QCOMPARE(QString(actual.c_str()), QString(expected.c_str()));
    //
    expected = "ell";
    delete signal;
    signal = new algorithms::ByteArrSignal(input_buf + 1, expected.length());
    actual = signal->to_std_string();
    QCOMPARE(QString(actual.c_str()), QString(expected.c_str()));
    //
    expected = "";
    delete signal;
    signal = new algorithms::ByteArrSignal((char*)nullptr, 0);
    actual = signal->to_std_string();
    QCOMPARE(QString(actual.c_str()), QString(expected.c_str()));
    //
    expected = "";
    delete signal;
    signal = new algorithms::ByteArrSignal("\0", strlen("\0"));
    actual = signal->to_std_string();
    QCOMPARE(QString(actual.c_str()), QString(expected.c_str()));
}

void ByteArrSignal_Test::test_to_bytes_ByteArrSignal()
{
    const int BUF_LEN = 5;
    char buf[BUF_LEN]{'h', 'e', 'l', 'l', 'o'};
    //
    algorithms::InputSignalBase* signal = new algorithms::ByteArrSignal(buf, BUF_LEN);
    size_t actual_size;
    char* actual = signal->to_bytes(actual_size);
    QCOMPARE(actual_size, BUF_LEN);
    for (size_t i = 0; i < actual_size; i++) {
        QCOMPARE(actual[i], buf[i]);
    }
    delete[] actual;
    //
    delete signal;
    signal = new algorithms::ByteArrSignal(buf, BUF_LEN-1);
    actual = signal->to_bytes(actual_size);
    QCOMPARE(actual_size, BUF_LEN-1);
    for (size_t i = 0; i < actual_size; i++) {
        QCOMPARE(actual[i], buf[i]);
    }
    delete[] actual;
    //
    delete signal;
    signal = new algorithms::ByteArrSignal(buf + 1, BUF_LEN - 2);
    actual = signal->to_bytes(actual_size);
    QCOMPARE(actual_size, BUF_LEN-2);
    for (size_t i = 0; i < actual_size; i++) {
        QCOMPARE(actual[i], buf[i+1]);
    }
    delete[] actual;
    //
    delete signal;
    signal = new algorithms::ByteArrSignal((char*)nullptr, 0);
    actual = signal->to_bytes(actual_size);
    QCOMPARE(actual_size, 0);
    QCOMPARE(actual, nullptr);
    //
    delete signal;
    signal = new algorithms::ByteArrSignal("\0", strlen("\0"));
    actual = signal->to_bytes(actual_size);
    QCOMPARE(actual_size, 0);
    QCOMPARE(actual, nullptr);
}

void ByteArrSignal_Test::test_as_bytes_ByteArrSignal()
{
    const int BUF_LEN = 5;
    char buf[BUF_LEN]{'h', 'e', 'l', 'l', 'o'};
    //
    algorithms::InputSignalBase* signal = new algorithms::ByteArrSignal(buf, BUF_LEN);
    size_t actual_size;
    char* actual = signal->as_bytes(actual_size);
    QCOMPARE(actual_size, BUF_LEN);
    for (size_t i = 0; i < actual_size; i++) {
        QCOMPARE(actual[i], buf[i]);
    }
    //
    delete signal;
    signal = new algorithms::ByteArrSignal(buf, BUF_LEN-1);
    actual = signal->as_bytes(actual_size);
    QCOMPARE(actual_size, BUF_LEN-1);
    for (size_t i = 0; i < actual_size; i++) {
        QCOMPARE(actual[i], buf[i]);
    }
    //
    delete signal;
    signal = new algorithms::ByteArrSignal(buf + 1, BUF_LEN - 2);
    actual = signal->as_bytes(actual_size);
    QCOMPARE(actual_size, BUF_LEN-2);
    for (size_t i = 0; i < actual_size; i++) {
        QCOMPARE(actual[i], buf[i+1]);
    }
    //
    delete signal;
    signal = new algorithms::ByteArrSignal((char*)nullptr, 0);
    actual = signal->as_bytes(actual_size);
    QCOMPARE(actual_size, 0);
    QCOMPARE(actual, nullptr);
    //
    delete signal;
    signal = new algorithms::ByteArrSignal("\0", strlen("\0"));
    actual = signal->as_bytes(actual_size);
    QCOMPARE(actual_size, 0);
    QCOMPARE(actual, nullptr);
}

QTEST_APPLESS_MAIN(ByteArrSignal_Test)

#include "tst_bytearrsignal_test.moc"
