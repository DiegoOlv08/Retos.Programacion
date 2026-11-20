#include <stdio.h>
#include <string.h>

#define TOTAL 3

struct Usuario {
    char nombre[50];
    char usuario[30];
    char correo[50];
    int edad;
    float altura;
};

/* Quita el \n que deja fgets */
void quitarSalto(char* cadena)
{
    cadena[strcspn(cadena, "\n")] = '\0';
}

/* Limpia el salto de línea que deja scanf_s en el búfer */
void limpiarBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

/* Recibe un apuntador a una estructura y la captura */
void capturar(struct Usuario* u)
{
    printf("Nombre: ");
    fgets(u->nombre, sizeof(u->nombre), stdin);
    quitarSalto(u->nombre);

    printf("Usuario: ");
    fgets(u->usuario, sizeof(u->usuario), stdin);
    quitarSalto(u->usuario);

    printf("Correo: ");
    fgets(u->correo, sizeof(u->correo), stdin);
    quitarSalto(u->correo);

    printf("Edad: ");
    scanf_s("%d", &u->edad);

    printf("Altura: ");
    scanf_s("%f", &u->altura);
    limpiarBuffer();
}

/* Recibe un apuntador a una estructura y la muestra */
void mostrar(const struct Usuario* u)
{
    printf("%-15s %-12s %-22s %3d  %.2f m\n",
        u->nombre, u->usuario, u->correo, u->edad, u->altura);
}

int main(void)
{
    /* 1. Arreglo de estructuras */
    struct Usuario lista[TOTAL];

    /* 2. Apuntador que apunta al primer elemento del arreglo */
    struct Usuario* p = lista;

    /* 3. Capturar recorriendo el arreglo con el apuntador */
    for (int i = 0; i < TOTAL; i++) {
        printf("\n--- Usuario %d ---\n", i + 1);
        capturar(p);   /* p apunta al elemento actual */
        p++;           /* avanza al siguiente elemento */
    }

    /* 4. Regresar el apuntador al inicio y mostrar con aritmética de apuntadores */
    p = lista;
    printf("\n=== Lista de usuarios (con p++) ===\n");
    for (int i = 0; i < TOTAL; i++) {
        mostrar(p);
        p++;
    }

    /* 5. Otra forma: *(lista + i) y el operador -> con (lista + i) */
    printf("\n=== Lista de usuarios (con lista + i) ===\n");
    for (int i = 0; i < TOTAL; i++) {
        printf("%d) %s tiene %d anios\n",
            i + 1, (lista + i)->nombre, (*(lista + i)).edad);
    }

    /* 6. Calcular el promedio de edad usando un apuntador */
    int suma = 0;
    for (p = lista; p < lista + TOTAL; p++) {
        suma += p->edad;
    }
    printf("\nPromedio de edad: %.1f\n", (float)suma / TOTAL);

    return 0;
}