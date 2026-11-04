#include <stdio.h>

#include "celsius.h"

/* Convert a Fahrenheit temperature to celsius*/

// TODO create unit tests
int main(void)
{

    float fahrenheit, celsius;

    printf("Enter Fahrenheit temperature: ");
    scanf("%f", &fahrenheit);

    celsius = fahrenheit_to_celsius(fahrenheit);

    printf("Celsius equivalent: %.1f \n", celsius);

    return 0;
}