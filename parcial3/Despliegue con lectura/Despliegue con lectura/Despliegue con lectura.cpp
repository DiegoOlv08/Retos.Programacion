//Diego Alejandro Olvera Lira
//UPT Programacion Estructurada
//Arturo Negrete
//Despliegue con lectura
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monitos.h"     /* nuestro encabezado, va entre comillas */

 /* Lee el archivo y guarda cada monito en la lista.
    Regresa la cantidad de monitos leídos, o un número negativo si hay error. */
int leerMonitos(const char* nombreArchivo, Monito* lista[])
{
    FILE* archivo;
    char linea[100];
    char* apunte;
    Monito* aptMonito = NULL;
    int cntdr = 0;

    /* Abrir el archivo en modo lectura */
    if (fopen_s(&archivo, nombreArchivo, "r") != 0) {
        printf("Error: No se pudo abrir el archivo. Verifica que exista.\n");
        return -1;
    }

    /* Leer línea por línea hasta llegar al final (EOF) */
    while (fgets(linea, sizeof(linea), archivo) != NULL) {

        /* Reservar memoria justa para la línea y copiarla */
        apunte = (char*)malloc(strlen(linea) + 1);
        if (apunte == NULL) {
            printf("Error: No se pudo asignar memoria para la linea.\n");
            fclose(archivo);
            return -2;
        }
        strcpy_s(apunte, strlen(linea) + 1, linea);

        /* Si no hay monito actual o ya está lleno, se crea uno nuevo */
        if (aptMonito == NULL || aptMonito->elementos >= MAX_LINEAS) {
            if (cntdr >= MAX_MONITOS) {
                printf("Advertencia: Se alcanzo el limite de monitos.\n");
                free(apunte);
                continue;
            }
            aptMonito = (Monito*)malloc(sizeof(Monito));
            if (aptMonito == NULL) {
                printf("Error: No se pudo asignar memoria para el monito.\n");
                free(apunte);
                fclose(archivo);
                return -2;
            }
            aptMonito->elementos = 0;
            lista[cntdr] = aptMonito;
            cntdr++;
        }

        /* Guardar la línea en el monito actual */
        aptMonito->arreglo[aptMonito->elementos] = apunte;
        aptMonito->elementos++;
    }

    fclose(archivo);
    return cntdr;
}

int main()
{
    Monito* lista[MAX_MONITOS];
    int cntdr;

    /* 1. Leer el archivo (la función está arriba, el prototipo en monitos.h) */
    cntdr = leerMonitos("ahorcado2.txt", lista);
    if (cntdr < 0) {
        return 1;
    }
    printf("\n---------- La lista se ha cargado (%d monitos) ----------\n", cntdr);
    printf("Presiona Enter para ver los monitos...");
    getchar();

    /* 2. Desplegar los monitos uno por uno */
    for (int i = 0; i < cntdr; i++) {
        system("cls");   /* limpiar la pantalla */
        printf("\n--- Monito %d ---\n\n", i + 1);
        for (int j = 0; j < lista[i]->elementos; j++) {
            printf("%s", lista[i]->arreglo[j]);
        }
        printf("\n-------------------\n");
        getchar();   /* esperar Enter antes de continuar */
    }

    /* 3. Liberar la memoria de cada línea y de cada monito */
    for (int i = 0; i < cntdr; i++) {
        for (int j = 0; j < lista[i]->elementos; j++) {
            free(lista[i]->arreglo[j]);
        }
        free(lista[i]);
    }

    return 0;
}