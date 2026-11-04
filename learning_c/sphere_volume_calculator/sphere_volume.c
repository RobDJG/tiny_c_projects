#include "volume_calculator.h"
#include <math.h>
#define SCALE_FRACTION (4.0f / 3.0f)

float sphere_volume(float radius)
{

    float cubic_radius = radius * radius * radius;

    float volume = SCALE_FRACTION * M_PI * cubic_radius;

    return volume;
}
