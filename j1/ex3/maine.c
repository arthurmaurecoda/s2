#include <stdio.h>

double compute_average(double nb1, double nb2, double nb3)
{
    return (nb1 + nb2 + nb3) / 3.0;
}

int main(void)
{
    printf("%f\n", compute_average(1.0, 2.0, 4.0));
    return 0;
}