#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double a, b;

    printf("Ingresa el primer numero: ");
    scanf("%lf", &a);

    printf("Ingresa el segundo numero: ");
    scanf("%lf", &b);

    printf("\nSuma: %.2f\n", a + b);
    printf("Resta: %.2f\n", a - b);
    printf("Multiplicacion: %.2f\n", a * b);

    if (b != 0) {
        printf("Division: %.2f\n", a / b);
    }
    else {
        printf("Division: no se puede dividir entre cero\n");
    }

    return 0;
}