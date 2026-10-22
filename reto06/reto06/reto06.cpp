#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b, c;

    printf("Ingresa el primer numero: ");
    scanf("%d", &a);

    printf("Ingresa el segundo numero: ");
    scanf("%d", &b);

    printf("Ingresa el tercer numero: ");
    scanf("%d", &c);

    if (a >= b && a >= c) {
        printf("El mayor es: %d\n", a);
    }
    else {
        if (b >= a && b >= c) {
            printf("El mayor es: %d\n", b);
        }
        else {
            printf("El mayor es: %d\n", c);
        }
    }

    return 0;
}