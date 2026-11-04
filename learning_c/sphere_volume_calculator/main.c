#include <stdio.h>

#include "volume_calculator.h"

int main(void)
{

    float input_radius;

    printf("Enter the radius of the sphere:");

    scanf("%f", &input_radius);

    printf("The volume is: %.2f \n", sphere_volume(input_radius));

    return 0;
}