#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    char palabra[100];
    int i, vocales = 0;

    printf("Ingresa una palabra: ");
    scanf("%99s", palabra);

    for (i = 0; palabra[i] != '\0'; i++) {
        switch (palabra[i]) {
        case 'a': case 'A':
        case 'e': case 'E':
        case 'i': case 'I':
        case 'o': case 'O':
        case 'u': case 'U':
            vocales++;
            break;
        default:
            break;
        }
    }

    printf("La palabra \"%s\" tiene %d vocales\n", palabra, vocales);

    return 0;
}