#include "unity.h"
#include "dweight.h"

void setUp(void) {}
void tearDown(void) {}

void test_volume_multiplies_dimensions(void)
{
    TEST_ASSERT_EQUAL_INT(24, calc_volume(2, 3, 4));
}

void test_volume_is_zero_when_a_dimension_is_zero(void)
{
    TEST_ASSERT_EQUAL_INT(0, calc_volume(5, 0, 7));
}

void test_weight_of_zero_volume_is_zero(void)
{
    TEST_ASSERT_EQUAL_INT(0, calc_dimensional_weight(0));
}

void test_weight_rounds_up_for_tiny_volume(void)
{
    TEST_ASSERT_EQUAL_INT(1, calc_dimensional_weight(1));
}

void test_weight_exact_boundary_does_not_round_up(void)
{
    TEST_ASSERT_EQUAL_INT(1, calc_dimensional_weight(166));
}

void test_weight_rounds_up_just_past_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(2, calc_dimensional_weight(167));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_volume_multiplies_dimensions);
    RUN_TEST(test_volume_is_zero_when_a_dimension_is_zero);
    RUN_TEST(test_weight_of_zero_volume_is_zero);
    RUN_TEST(test_weight_rounds_up_for_tiny_volume);
    RUN_TEST(test_weight_exact_boundary_does_not_round_up);
    RUN_TEST(test_weight_rounds_up_just_past_boundary);
    return UNITY_END();
}
