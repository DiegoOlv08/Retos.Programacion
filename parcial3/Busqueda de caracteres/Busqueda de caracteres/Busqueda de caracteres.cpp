#include <stdio.h>
#include <string.h>

#define TAM 100

int main(void)
{
    char frase[TAM];     /* arreglo de caracteres para la frase */
    char letra;          /* carácter que se va a buscar */
    int encontrado = 0;  /* 0 = no encontrado, 1 = encontrado */

    /* 1. Capturar la frase completa, con espacios */
    printf("Escribe una frase: ");
    fgets(frase, sizeof(frase), stdin);

    /* fgets guarda el salto de línea (\n); se cambia por el fin de cadena */
    frase[strcspn(frase, "\n")] = '\0';

    /* 2. Capturar un solo carácter */
    printf("Escribe el caracter a buscar: ");
    scanf_s(" %c", &letra, 1);

    /* 3. Recorrer la frase buscando el carácter */
    printf("\nFrase: \"%s\"\n", frase);

    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == letra) {
            printf("El caracter '%c' fue hallado en la posicion %d\n", letra, i + 1);
            encontrado = 1;
        }
    }

    /* 4. Si no se encontró ninguna vez, avisar */
    if (!encontrado) {
        printf("El caracter '%c' NO fue hallado en la frase.\n", letra);
    }

    return 0;
}