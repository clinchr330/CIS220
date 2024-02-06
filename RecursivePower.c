// Rafael Clinch
//Chpt2 PA
#include <stdio.h>

// Recursive function to calculate power
int power(int base, int exponent) {
    if (exponent == 1) {
        return base;
    } else {
        return base * power(base, exponent - 1);
    }
}

int main() {
    int base, exponent, result;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    result = power(base, exponent);

    printf("%d^%d = %d\n", base, exponent, result);

    return 0;
}
