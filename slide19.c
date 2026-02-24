#include <stdio.h>

int main() {
    double a = 57.0;
    double b = 57.;
    double c = 57.0e0;
    double d = 57E0;
    double e = 5.7e1;
    double f = 5.7e+1;
    double g = .57e2;
    double h = 570.e-1;

    printf("Different representations of 57.0 in C:\n\n");

    printf("57.0     = %f\n", a);
    printf("57.      = %f\n", b);
    printf("57.0e0   = %f\n", c);
    printf("57E0     = %f\n", d);
    printf("5.7e1    = %f\n", e);
    printf("5.7e+1   = %f\n", f);
    printf(".57e2    = %f\n", g);
    printf("570.e-1  = %f\n", h);

    return 0;
}
