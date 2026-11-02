#include "dweight.h"

#define INCHES_PER_POUND 166

int calc_volume(int height, int length, int width)
{
    return height * length * width;
}

int calc_dimensional_weight(int volume)
{
    return (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
}
