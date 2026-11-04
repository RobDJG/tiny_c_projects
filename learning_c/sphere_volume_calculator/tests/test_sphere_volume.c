#include "unity.h"
#include "volume_calculator.h"

void setUp(void) {}
void tearDown(void) {}

void test_volume_of_zero_radius_is_zero(void)
{
    TEST_ASSERT_FLOAT_WITHIN(0.0001f, 0.0f, sphere_volume(0.0f));
}

void test_volume_of_unit_radius(void)
{
    /* 4/3 * pi */
    TEST_ASSERT_FLOAT_WITHIN(0.0001f, 4.18879f, sphere_volume(1.0f));
}

void test_volume_of_radius_two(void)
{
    /* 4/3 * pi * 8 */
    TEST_ASSERT_FLOAT_WITHIN(0.001f, 33.51032f, sphere_volume(2.0f));
}

void test_volume_of_fractional_radius(void)
{
    /* 4/3 * pi * 0.125 */
    TEST_ASSERT_FLOAT_WITHIN(0.0001f, 0.523599f, sphere_volume(0.5f));
}

void test_volume_of_large_radius(void)
{
    /* 4/3 * pi * 1000 */
    TEST_ASSERT_FLOAT_WITHIN(0.01f, 4188.790f, sphere_volume(10.0f));
}

void test_volume_scales_with_cube_of_radius(void)
{
    /* doubling the radius multiplies the volume by 8 */
    float v1 = sphere_volume(3.0f);
    float v2 = sphere_volume(6.0f);
    TEST_ASSERT_FLOAT_WITHIN(0.01f, v1 * 8.0f, v2);
}

void test_volume_of_negative_radius_is_negative(void)
{
    /* documents current behavior: no input validation, cube keeps the sign */
    TEST_ASSERT_FLOAT_WITHIN(0.0001f, -4.18879f, sphere_volume(-1.0f));
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_volume_of_zero_radius_is_zero);
    RUN_TEST(test_volume_of_unit_radius);
    RUN_TEST(test_volume_of_radius_two);
    RUN_TEST(test_volume_of_fractional_radius);
    RUN_TEST(test_volume_of_large_radius);
    RUN_TEST(test_volume_scales_with_cube_of_radius);
    RUN_TEST(test_volume_of_negative_radius_is_negative);
    return UNITY_END();
}
