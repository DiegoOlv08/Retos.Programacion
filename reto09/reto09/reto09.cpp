#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void intercambiar(int* x, int* y) {
    int temporal = *x;
    *x = *y;
    *y = temporal;
}

int main() {
    int a, b;

    printf("Ingresa el primer numero: ");
    scanf("%d", &a);

    printf("Ingresa el segundo numero: ");
    scanf("%d", &b);

    printf("\nAntes del intercambio: a = %d, b = %d\n", a, b);

    intercambiar(&a, &b);

    printf("Despues del intercambio: a = %d, b = %d\n", a, b);

    return 0;
}