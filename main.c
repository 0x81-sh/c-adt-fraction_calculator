#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"

PFraction readFraction ();
char getSign ();
PFraction calculate (PFraction a, PFraction b, char sign);

int main() {
    while (1) {
        printf("Enter fraction 1: \n");
        PFraction a = readFraction();

        printf("Enter fraction 2: \n");
        PFraction b = readFraction();

        char sign = getSign();
        PFraction result = calculate(a, b, sign);

        printf("\tResult: ");
        Fraction_show(result);

        printf("\n\n");
        Fraction_massDelete(3, result, a, b);
    }

    return 0;
}

PFraction readFraction () {
    fflush(stdin);
    int num, denom;

    printf("Enter number: ");
    scanf("%d", &num);

    printf("Enter denom: ");
    scanf("%d", &denom);

    return Fraction_create(num, denom);
}

char getSign () {
    fflush(stdin);

    char sign;
    printf("Enter operator (+ - * / e): ");
    scanf("%c", &sign);

    return sign;
}

PFraction calculate (PFraction a, PFraction b, char sign) {
    switch (sign) {
        case '+':
            return Fraction_add(a, b);
        case '-':
            return Fraction_subtract(a, b);
        case '*':
            return Fraction_multiply(a, b);
        case '/':
            return Fraction_divide(a, b);
        case 'e':
            exit(0);
        default:
            printf("Invalid operation.\n");
            return Fraction_create(0, 1);
    }
}