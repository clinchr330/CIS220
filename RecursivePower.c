// Rafael Clinch
// Chpt2 PA
#include <stdio.h>


int power(int base, int exponent) { // Recursive function that calculates power
    if (exponent == 1) {
        return base;
    } else {
        return base * power(base, exponent - 1);
    }
}

int main() {
    int base, exponent, result;

    printf("Enter base: "); // Prompt user for base number
    scanf("%d", &base);

    printf("Enter exponent: "); // Prompt user for exponent
    scanf("%d", &exponent);

    result = power(base, exponent); // Calls power function to perform the ccalculation

    printf("Value is %d\n", result);

    return 0;
}
