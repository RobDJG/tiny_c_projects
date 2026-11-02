#include <stdio.h>
#include "dweight.h"

int main(void)
{

    int height, length, width, volume, dimensional_weight;

    printf("Welcome to the dimensional weight calculator, please enter the dimensions of the box: \n\n");

    printf("Enter height of the box: ");
    scanf("%d", &height);

    printf("Enter lengt of the box: ");
    scanf("%d", &length);

    printf("Enter width of the box: ");
    scanf("%d", &width);

    volume = calc_volume(height, length, width);

    dimensional_weight = calc_dimensional_weight(volume);

    printf("\n\n**********Results**********\n");

    printf("\nVolume (cubic inches): %d\n", volume);

    printf("\nDimensional weight (pounds): %d\n", dimensional_weight);

    printf("\n******************************");

    return 0;
}
