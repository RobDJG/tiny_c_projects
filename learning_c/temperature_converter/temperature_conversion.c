#include "celsius.h"
#include <math.h>
#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

float fahrenheit_to_celsius(float temperature)
{

    float celsius = (temperature - FREEZING_PT) * SCALE_FACTOR;

    return celsius;
}