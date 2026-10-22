#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    struct Estudiante alumno;

    printf("Ingresa el nombre del alumno: ");
    scanf("%49s", alumno.nombre);

    printf("Ingresa la edad: ");
    scanf("%d", &alumno.edad);

    printf("Ingresa el promedio: ");
    scanf("%f", &alumno.promedio);

    printf("\n--- Registro de Estudiante ---\n");
    printf("Nombre: %s\n", alumno.nombre);
    printf("Edad: %d anos\n", alumno.edad);
    printf("Promedio: %.2f\n", alumno.promedio);

    return 0;
}