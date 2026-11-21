#ifndef monitos_h
#define monitos_h

#define MAX_MONITOS 7     /* tamaño máximo de la lista de monitos */
#define MAX_LINEAS  11    /* líneas que tiene cada monito */

/* "Molde" de la estructura */
typedef struct monito {
    char* arreglo[MAX_LINEAS];   /* apuntadores a cada línea del dibujo */
    int elementos;               /* cuántas líneas tiene este monito */
} Monito;

/* Lee el archivo y llena la lista de monitos.
   Regresa cuántos monitos leyó, o un número negativo si hubo error. */
int leerMonitos(const char* nombreArchivo, Monito* lista[]);

#endif