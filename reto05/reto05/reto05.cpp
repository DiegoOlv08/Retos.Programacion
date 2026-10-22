#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int numero, i;
    unsigned long long factorial = 1;

    printf("Ingresa un numero entero positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("El factorial no existe para numeros negativos\n");
    }
    else if (numero > 20) {
        printf("El numero es muy grande, el resultado desborda el tipo de dato\n");
    }
    else {
        for (i = 1; i <= numero; i++) {
            factorial = factorial * i;
        }
        printf("El factorial de %d es %llu\n", numero, factorial);
    }

    return 0;
}