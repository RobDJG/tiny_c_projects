#include "unity.h"
#include "celsius.h"

void setUp(void) {}
void tearDown(void) {}

void test_fahrenheit_to_celsius_freezing(void)
{
    TEST_ASSERT_FLOAT_WITHIN(0.01f, 0.0f, fahrenheit_to_celsius(32.0f));
}

void test_fahrenheit_to_celsius_boiling(void)
{
    TEST_ASSERT_FLOAT_WITHIN(0.01f, 100.0f, fahrenheit_to_celsius(212.0f));
}

void test_fahrenheit_to_celsius_body_temp(void)
{
    TEST_ASSERT_FLOAT_WITHIN(0.01f, 37.0f, fahrenheit_to_celsius(98.6f));
}

void test_fahrenheit_to_celsius_negative(void)
{
    TEST_ASSERT_FLOAT_WITHIN(0.01f, -40.0f, fahrenheit_to_celsius(-40.0f));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_fahrenheit_to_celsius_freezing);
    RUN_TEST(test_fahrenheit_to_celsius_boiling);
    RUN_TEST(test_fahrenheit_to_celsius_body_temp);
    RUN_TEST(test_fahrenheit_to_celsius_negative);
    return UNITY_END();
}
