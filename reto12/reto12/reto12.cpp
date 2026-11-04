//Diego Alejandro Olvera Lira
//UPT Programacion Estructurada
//Arturo Negrete
//Uso de apuntadores 
#include <stdio.h>

void intercambiar(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    /* 1. Apuntadores con variables simples */
    int A = 10, B = 15;
    int* aptr = &A;

    printf("=== Variables simples ===\n");
    printf("A = %d, direccion de A = %p\n", A, (void*)&A);
    printf("aptr apunta a %p y su valor es %d\n", (void*)aptr, *aptr);

    *aptr = 20;  // modificar A a traves del apuntador
    printf("Despues de *aptr = 20, A = %d\n", A);

    aptr = &B;   // apuntar a otra variable
    printf("Ahora aptr apunta a B: valor %d, direccion %p\n", *aptr, (void*)aptr);

    /* 2. Apuntador a apuntador */
    int** aptr2 = &aptr;
    printf("\n=== Apuntador a apuntador ===\n");
    printf("**aptr2 = %d (llega a B)\n", **aptr2);

    /* 3. Paso por referencia */
    printf("\n=== Funcion con apuntadores ===\n");
    printf("Antes: A = %d, B = %d\n", A, B);
    intercambiar(&A, &B);
    printf("Despues de intercambiar: A = %d, B = %d\n", A, B);

    /* 4. Arreglo de enteros */
    int numeros[5] = { 1, 2, 3, 4, 5 };
    int* nptr = numeros;  // el nombre del arreglo ya es una direccion

    printf("\n=== Arreglo de enteros ===\n");
    for (int i = 0; i < 5; i++) {
        printf("numeros[%d] = %d | *(nptr + %d) = %d | direccion %p\n",
            i, numeros[i], i, *(nptr + i), (void*)(nptr + i));
    }

    for (int i = 0; i < 5; i++) {
        *(nptr + i) *= 2;  // modificar el arreglo con el apuntador
    }
    printf("Arreglo duplicado con apuntador: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", nptr[i]);  // notacion de indice sobre el apuntador
    }
    printf("\n");

    /* 5. Arreglo de caracteres (cadena) */
    char texto[] = "Diego Olvera";
    char* tptr = texto;

    printf("\n=== Cadena de caracteres ===\n");
    while (*tptr != '\0') {
        printf("%c y su direccion %p\n", *tptr, (void*)tptr);
        tptr++;  // avanzar el apuntador
    }

    return 0;
}
