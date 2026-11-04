//Diego Alejandro Olvera Lira
//UPT Programacion Estructurada
//Arturo Negrete
//Búsqueda en texto 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char texto[201];
    char caracter;
    int encontrados = 0;

    printf("Introduce una frase: ");
    scanf_s("%[^\n]", texto, (unsigned int)sizeof(texto));

    printf("Introduce un caracter a buscar: ");
    scanf_s(" %c", &caracter, 1);

    int largo = (int)strlen(texto);

    for (int i = 0; i < largo; i++) {
        // tolower() para no distinguir mayusculas y minusculas
        if (tolower((unsigned char)texto[i]) == tolower((unsigned char)caracter)) {
            encontrados++;
            printf("Caracter '%c' encontrado en la posicion %d\n", caracter, i + 1);
        }
    }

    if (encontrados == 0) {
        printf("El caracter '%c' no aparece en la frase.\n", caracter);
    }

    return 0;
}