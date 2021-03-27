#include <stdio.h>

/* print Celsius-Fahrenheit table
   for celsius = 0, 20, ..., 300 */

int main()
{
    double celsius, fahr;
    int lower, upper, step;

    lower = -20; /* lower limit of temperature table */
    upper = 150; /* upper limit */
    step = 10;   /* step size */

    printf("Celsius\tFahrenheit\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 * celsius) / 5.0 + 32.0;
        printf("%7.0f\t%10.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
