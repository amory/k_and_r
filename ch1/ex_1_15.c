#include <stdio.h>

double fahr_to_celcius(int fahr);

int main()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, fahr_to_celcius(fahr));
}

double fahr_to_celcius(int fahr)
{
    return (5.0/9.0) * (fahr-32);
}
