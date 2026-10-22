#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int numero, i;

    printf("Ingresa un numero: ");
    scanf("%d", &numero);

    printf("\nTabla de multiplicar del %d:\n", numero);

    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0;
}