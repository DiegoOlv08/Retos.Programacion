#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int numeros[5] = { 0 };
    int i, suma = 0;

    for (i = 0; i < 5; i++) {
        printf("Ingresa el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    for (i = 0; i < 5; i++) {
        suma = suma + numeros[i];
    }

    printf("\nLos numeros son: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\nLa suma es: %d\n", suma);

    return 0;
}