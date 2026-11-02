#include "dweight.h"

int calc_volume(int height, int length, int width)
{
    return height * length * width;
}

int calc_dimensional_weight(int volume)
{
    return (volume + 165) / 166;
}
