#include <QtTest>

#include <../../../memory_prototype/utils/bithelper.h>
#include <../../../memory_prototype/utils/randomizer.h>

class Utils_Test : public QObject
{
    Q_OBJECT

public:
    Utils_Test();
    ~Utils_Test();

private slots:
    // BitsHelper tests
    void test_BitHelper_count_bits();
    void test_BitHelper_verify_bits_string();
    void test_BitHelper_set_bit();
    void test_BitHelper_bits2bytes();
    // Randomizer tests
    void test_Randomizer_next_int();
    void test_Randomizer_next_double();

};

Utils_Test::Utils_Test()
{

}

Utils_Test::~Utils_Test()
{

}

void Utils_Test::test_BitHelper_count_bits()
{
    //
    char buffer[4]{(char)0b11001100, (char)0b00110011, (char)0b11110000, (char)0b00001111};
    size_t expected_bits_count = 16;
    size_t actual_bits_count = utils::BitHelper::count_bits(buffer, 4);
    QCOMPARE(actual_bits_count, expected_bits_count);
    //
    expected_bits_count = 12;
    actual_bits_count = utils::BitHelper::count_bits(buffer, 3);
    QCOMPARE(actual_bits_count, expected_bits_count);
    //
    for (size_t i = 0; i < 4; i++) {
        buffer[i] = i + 48;
    }
    std::string std_buffer = "0123";
    expected_bits_count = utils::BitHelper::count_bits(buffer, 4);
    actual_bits_count = utils::BitHelper::count_bits(std_buffer);
    QCOMPARE(actual_bits_count, expected_bits_count);
}

void Utils_Test::test_BitHelper_verify_bits_string()
{
    //
    const int N = 10;
    char bits[N]{'1', '1', '0', '0', '1', '\0'};
    bool ok = utils::BitHelper::verify_bits_string(bits);
    QVERIFY(ok);
    //
    bits[0] = '2';
    ok = utils::BitHelper::verify_bits_string(bits);
    QVERIFY(!ok);
    //
    ok = utils::BitHelper::verify_bits_string("11001110101010101");
    QVERIFY(ok);
    //
    ok = utils::BitHelper::verify_bits_string("110011101010210101");
    QVERIFY(!ok);
    //
    std::string bits_str = "11101010101";
    ok = utils::BitHelper::verify_bits_string(bits_str);
    QVERIFY(ok);
    //
    bits_str = "111012010101";
    ok = utils::BitHelper::verify_bits_string(bits_str);
    QVERIFY(!ok);
}

void Utils_Test::test_BitHelper_set_bit()
{
    //
    char byte = 0b11110000;
    char expected = 0b11110001;
    char actual = utils::BitHelper::set_bit(byte, 0, '1');
    QCOMPARE(actual, expected);
    //
    expected = 0b11110011;
    actual = utils::BitHelper::set_bit(actual, 1, '1');
    QCOMPARE(actual, expected);
    //
    expected = 0b11110111;
    actual = utils::BitHelper::set_bit(actual, 2, '1');
    QCOMPARE(actual, expected);
    //
    expected = 0b11111111;
    actual = utils::BitHelper::set_bit(actual, 3, '1');
    QCOMPARE(actual, expected);
    //
    expected = 0b11101111;
    actual = utils::BitHelper::set_bit(actual, 4, '0');
    QCOMPARE(actual, expected);
    //
    expected = 0b11001111;
    actual = utils::BitHelper::set_bit(actual, 5, '0');
    QCOMPARE(actual, expected);
    //
    expected = 0b10001111;
    actual = utils::BitHelper::set_bit(actual, 6, '0');
    QCOMPARE(actual, expected);
    //
    expected = 0b00001111;
    actual = utils::BitHelper::set_bit(actual, 7, '0');
    QCOMPARE(actual, expected);
}

void Utils_Test::test_BitHelper_bits2bytes()
{
    //
    std::string bits_str = "0110000100000000";  // "a\0"
    size_t actual_size;
    char* actual = utils::BitHelper::bits2bytes(bits_str.c_str(), actual_size);
    QCOMPARE(QString(actual), QString("a"));
    delete[] actual;
    //
    bits_str = "110000100000000";  // "a\0"
    actual = utils::BitHelper::bits2bytes(bits_str.c_str(), actual_size);
    QCOMPARE(QString(actual), QString("a"));
    delete[] actual;
    //
    bits_str = "011000010110001000000000";  // "ab\0"
    actual = utils::BitHelper::bits2bytes(bits_str.c_str(), actual_size);
    QCOMPARE(QString(actual), QString("ab"));
    delete[] actual;
    //
    bits_str = "00110000011000010110001000000000";  // "0ab\0"
    actual = utils::BitHelper::bits2bytes(bits_str.c_str(), actual_size);
    QCOMPARE(QString(actual), QString("0ab"));
    delete[] actual;
    //
    bits_str = "110000011000010110001000000000";  // "0ab\0"
    actual = utils::BitHelper::bits2bytes(bits_str.c_str(), actual_size);
    QCOMPARE(QString(actual), QString("0ab"));
    delete[] actual;
}

void Utils_Test::test_Randomizer_next_int()
{
    //
    int32_t expected = 1;
    int32_t actual = utils::Randomizer::next_int(expected, expected);
    QCOMPARE(actual, expected);
    //
    const size_t set_size = 11;
    int32_t min_set[set_size]{-100, -90, -80, -70, -60, -50, -40, -30, -20, -10, 0};
    int32_t max_set[set_size]{100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    for (size_t i = 0; i < set_size; i++) {
        int32_t value = utils::Randomizer::next_int(min_set[i], max_set[i]);
        QVERIFY(value >= min_set[i] && value <= max_set[i]);
    }
}

void Utils_Test::test_Randomizer_next_double()
{
    double expected = 1.0;
    double actual = utils::Randomizer::next_double(expected, expected);
    QCOMPARE(actual, expected);
    //
    const size_t set_size = 11;
    double min_set[set_size]{-1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1, 0.0};
    double max_set[set_size]{1.0, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0};
    for (size_t i = 0; i < set_size; i++) {
        double value = utils::Randomizer::next_double(min_set[i], max_set[i]);
        QVERIFY(value >= min_set[i] && value <= max_set[i]);
    }
}

QTEST_APPLESS_MAIN(Utils_Test)

#include "tst_utils_test.moc"
