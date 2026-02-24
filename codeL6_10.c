//Program 10: Implicit Conversion Trap
// CSE Abid Malik

#include <stdio.h>

int main(void) {
    int a = 5;
    int b = 2;

    printf("%d\n", a / b);
    printf("%f\n", a / b);

    return 0;
}
