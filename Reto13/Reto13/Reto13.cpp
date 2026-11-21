//Diego Alejandro Olvera Lira
//UPT Programacion Estructurada
//Arturo Negrete
//Uso de estructuras
#include <stdio.h>
#include <string.h>

/* 1. Definir la estructura */
struct Usuario {
    char nombre[50];
    char usuario[30];
    char correo[50];
    char contrasena[30];
    int edad;
    float altura;
};

/* fgets guarda el salto de línea (\n); esta función lo quita */
void quitarSalto(char* cadena)
{
    cadena[strcspn(cadena, "\n")] = '\0';
}

int main(void)
{
    /* 2. Variable simple de tipo struct (sin apuntador ni malloc) */
    struct Usuario usuario1;

    /* 3. Capturar datos accediendo a cada campo con el operador punto (.) */
    printf("Ingrese el nombre: ");
    fgets(usuario1.nombre, sizeof(usuario1.nombre), stdin);
    quitarSalto(usuario1.nombre);

    printf("Ingrese el usuario: ");
    fgets(usuario1.usuario, sizeof(usuario1.usuario), stdin);
    quitarSalto(usuario1.usuario);

    printf("Ingrese el correo: ");
    fgets(usuario1.correo, sizeof(usuario1.correo), stdin);
    quitarSalto(usuario1.correo);

    printf("Ingrese la contrasena: ");
    fgets(usuario1.contrasena, sizeof(usuario1.contrasena), stdin);
    quitarSalto(usuario1.contrasena);

    printf("Ingrese la edad: ");
    scanf_s("%d", &usuario1.edad);

    printf("Ingrese la altura: ");
    scanf_s("%f", &usuario1.altura);

    /* 4. Mostrar los datos con el operador punto (.) */
    printf("\n=== Datos del usuario ===\n");
    printf("Nombre:     %s\n", usuario1.nombre);
    printf("Usuario:    %s\n", usuario1.usuario);
    printf("Correo:     %s\n", usuario1.correo);
    printf("Contrasena: %s\n", usuario1.contrasena);
    printf("Edad:       %d anios\n", usuario1.edad);
    printf("Altura:     %.2f m\n", usuario1.altura);

    return 0;
}
