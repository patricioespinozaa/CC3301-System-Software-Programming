#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void insertar(char c, char *s) {
    // Declarar un puntero auxiliar para mover los caracteres
    char *aux = s;

    // Encontrar el final de la cadena
    while (*aux != '\0') {
        aux++;
    }

    // Mover todos los caracteres hacia la derecha para hacer espacio para el nuevo carácter
    while (aux >= s) {
        *(aux + 1) = *aux;
        aux--;
    }

    // Insertar el nuevo carácter al inicio de la cadena
    *s = c;
}

int main() {
    char s1[5] = "ola";
    insertar('h', s1); // s1 debería ser el string "hola"
    printf("s1: %s\n", s1);

    char s2[20] = "oy inseguro, o no?";
    insertar('S', s2); // s2 debería ser el string "Soy inseguro, o no?"
    printf("s2: %s\n", s2);

    return 0;
}
