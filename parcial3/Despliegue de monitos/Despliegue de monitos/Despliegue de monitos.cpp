//Diego Alejandro Olvera Lira
//UPT Programacion Estructurada
//Arturo Negrete
//Despliegue de monitos 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MONITOS 7     /* tamaño máximo de la lista de monitos */
#define MAX_LINEAS  11    /* líneas que tiene cada monito */

 /* 1. Definir el "molde" de la estructura */
typedef struct monito {
    char* arreglo[MAX_LINEAS];   /* apuntadores a cada línea del dibujo */
    int elementos;               /* cuántas líneas tiene este monito */
} Monito;

int main()
{
    /* 2. Declarar un apuntador a FILE para manejar el archivo */
    FILE* archivo;

    /* Buffer para almacenar temporalmente cada línea leída */
    char* apunte;
    char linea[100];

    /* Lista de monitos */
    Monito* lista[MAX_MONITOS];
    Monito* aptMonito;
    int cntdr = 0;   /* contador de monitos leídos */

    /* 3. Abrir el archivo en modo lectura */
    errno_t result = fopen_s(&archivo, "ahorcado2.txt", "r");
    if (result != 0) {
        printf("Error: No se pudo abrir el archivo. Verifica que exista.\n");
        return 1;
    }

    /* 4. Reservar memoria para el primer monito */
    aptMonito = (Monito*)malloc(sizeof(Monito));
    aptMonito->elementos = 0;
    lista[cntdr] = aptMonito;
    cntdr++;

    /* 5. Leer el archivo línea por línea hasta llegar al final (EOF) */
    while (fgets(linea, sizeof(linea), archivo) != NULL) {

        /* Reservar memoria justa para la línea y copiarla */
        apunte = (char*)malloc(strlen(linea) + 1);
        if (apunte == NULL) {
            printf("Error: No se pudo asignar memoria para la línea.\n");
            fclose(archivo);
            return 2;
        }
        strcpy_s(apunte, strlen(linea) + 1, linea);

        if (aptMonito->elementos < MAX_LINEAS) {
            /* Todavía cabe en el monito actual */
            aptMonito->arreglo[aptMonito->elementos] = apunte;
            aptMonito->elementos++;
        }
        else if (cntdr < MAX_MONITOS) {
            /* El monito está lleno: crear uno nuevo y guardar ahí la línea */
            aptMonito = (Monito*)malloc(sizeof(Monito));
            aptMonito->elementos = 0;
            lista[cntdr] = aptMonito;
            cntdr++;
            aptMonito->arreglo[aptMonito->elementos] = apunte;
            aptMonito->elementos++;
        }
        else {
            printf("Advertencia: Se alcanzó el límite de elementos en el Monito y en su lista.\n");
            free(apunte);   /* liberar memoria si no se puede almacenar */
        }
    }
    printf("\n---------- La lista se ha cargado ----------\n");

    /* 6. Cerrar el archivo */
    fclose(archivo);

    /* 7. Imprimir el contenido de la lista de monitos */
    for (int i = 0; i < cntdr; i++) {
        system("cls");   /* limpiar la pantalla */
        printf("\n--- Monito %d ---\n\n", i + 1);
        for (int j = 0; j < lista[i]->elementos; j++) {
            printf("%s", lista[i]->arreglo[j]);
        }
        printf("\n-------------------\n");
        getchar();   /* esperar Enter antes de continuar al siguiente monito */
    }

    /* 8. Liberar la memoria de cada monito y de sus líneas */
    for (int i = 0; i < cntdr; i++) {
        for (int j = 0; j < lista[i]->elementos; j++) {
            free(lista[i]->arreglo[j]);
        }
        free(lista[i]);
    }

    return 0;
}