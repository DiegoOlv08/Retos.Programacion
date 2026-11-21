//Diego Alejandro Olvera Lira
//UPT Programacion Estructurada
//Arturo Negrete
//Despliegue de monitos 

/*
 * Nombre:   Diego Alejandro Olvera Lira
 * Carrera:  Ingeniería en Sistemas Electrónicos
 * Escuela:  Universidad Politécnica de Tulancingo
 * Materia:  (completa aquí)
 * Trabajo:  2 - Despliega monitos sin ninguna función (todo en main)
 * Fecha:    (completa aquí)
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_MONITOS 7    /* cuántos monitos hay */
#define NUM_LINEAS  11   /* líneas que tiene cada monito */

int main()
{
    /* Los 7 monitos del ahorcado escritos directamente en el código.
       Cada monito tiene 11 líneas. La barra invertida se escribe doble (\\). */
    const char* monitos[NUM_MONITOS][NUM_LINEAS] = {
        /* Monito 1: horca vacía */
        { "   +-----+", "   |     |", "   |", "   |", "   |", "   |",
          "   |", "   |", "   |", "   |", "===========" },

        /* Monito 2: cabeza */
        { "   +-----+", "   |     |", "   |     O", "   |", "   |", "   |",
          "   |", "   |", "   |", "   |", "===========" },

        /* Monito 3: torso */
        { "   +-----+", "   |     |", "   |     O", "   |     |", "   |     |", "   |",
          "   |", "   |", "   |", "   |", "===========" },

        /* Monito 4: un brazo */
        { "   +-----+", "   |     |", "   |     O", "   |    /|", "   |     |", "   |",
          "   |", "   |", "   |", "   |", "===========" },

        /* Monito 5: los dos brazos */
        { "   +-----+", "   |     |", "   |     O", "   |    /|\\", "   |     |", "   |",
          "   |", "   |", "   |", "   |", "===========" },

        /* Monito 6: una pierna */
        { "   +-----+", "   |     |", "   |     O", "   |    /|\\", "   |     |", "   |    /",
          "   |", "   |", "   |", "   |", "===========" },

        /* Monito 7: ahorcado completo */
        { "   +-----+", "   |     |", "   |     X", "   |    /|\\", "   |     |", "   |    / \\",
          "   |", "   |", "   |", "   |", "===========" }
    };

    /* Desplegar los monitos uno por uno */
    for (int i = 0; i < NUM_MONITOS; i++) {
        system("cls");   /* limpiar la pantalla */
        printf("\n--- Monito %d ---\n\n", i + 1);

        for (int j = 0; j < NUM_LINEAS; j++) {
            printf("%s\n", monitos[i][j]);
        }

        printf("\n-------------------\n");
        printf("Presiona Enter para continuar...");
        getchar();   /* esperar Enter antes de pasar al siguiente monito */
    }

    return 0;
}
        }
        free(lista[i]);
    }

    return 0;
}
