#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINEAS 15   /* máximo de líneas por figura */
#define MAX_ANCHO  40   /* máximo de caracteres por línea */

/* Una figura del ahorcado = varias líneas de texto */
struct Figura {
    char lineas[MAX_LINEAS][MAX_ANCHO];
    int numLineas;
};

/* Quita el \n que deja fgets */
void quitarSalto(char* cadena)
{
    cadena[strcspn(cadena, "\n")] = '\0';
}

/* Agrega una figura al arreglo dinámico (realloc).
   Recibe un apuntador al apuntador para poder cambiar la dirección del arreglo. */
int agregarFigura(struct Figura** lista, int* total, const struct Figura* nueva)
{
    struct Figura* temp = (struct Figura*)realloc(*lista, (*total + 1) * sizeof(struct Figura));
    if (temp == NULL) {
        printf("Error: no hay memoria suficiente.\n");
        return 0;
    }
    *lista = temp;
    (*lista)[*total] = *nueva;
    (*total)++;
    return 1;
}

int main(void)
{
    FILE* archivo = NULL;
    struct Figura* figuras = NULL;   /* arreglo dinámico de estructuras */
    int total = 0;
    char linea[MAX_ANCHO];
    struct Figura actual;
    actual.numLineas = 0;

    /* 1. Abrir el archivo para lectura */
    if (fopen_s(&archivo, "figuras.txt", "r") != 0 || archivo == NULL) {
        printf("No se pudo abrir figuras.txt\n");
        return 1;
    }

    /* 2. Leer línea por línea; la línea "---" separa una figura de otra */
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        quitarSalto(linea);

        if (strcmp(linea, "---") == 0) {
            /* Fin de una figura: guardarla en el arreglo dinámico */
            if (!agregarFigura(&figuras, &total, &actual)) {
                fclose(archivo);
                free(figuras);
                return 1;
            }
            actual.numLineas = 0;
        }
        else if (actual.numLineas < MAX_LINEAS) {
            strcpy_s(actual.lineas[actual.numLineas], MAX_ANCHO, linea);
            actual.numLineas++;
        }
    }

    /* La última figura no termina con "---", se guarda aquí */
    if (actual.numLineas > 0) {
        agregarFigura(&figuras, &total, &actual);
    }

    /* 3. Cerrar el archivo */
    fclose(archivo);

    printf("Se leyeron %d figuras del archivo.\n", total);
    printf("Presiona Enter para ver la secuencia del juego...");
    getchar();

    /* 4. Mostrar las figuras en forma secuencial con un apuntador */
    struct Figura* p = figuras;
    for (int i = 0; i < total; i++, p++) {
        system("cls");   /* limpiar pantalla (Windows) */
        printf("=== Errores: %d de %d ===\n\n", i, total - 1);

        for (int j = 0; j < p->numLineas; j++) {
            printf("%s\n", p->lineas[j]);
        }

        printf("\nPresiona Enter para continuar...");
        getchar();
    }

    /* 5. Liberar la memoria dinámica */
    free(figuras);
    figuras = NULL;

    return 0;
}