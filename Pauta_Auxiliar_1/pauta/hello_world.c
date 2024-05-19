#include <stdio.h> // incluye printf
#include <stdlib.h> // incluye atoi (str -> int)

// firma de una función, indica que existe.
int suma(int a, int b);

// argc es la cantidad de argumentos recibidos
// argv corresponde a un arreglo de strings con los argumentos
// argv[0] es el nombre del archivo.
int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Argumentos inválidos\n");
        return 0;
    }
    printf("hello world\n");
    int a = 3;
    int b = atoi(argv[1]);
    int r = suma(a,b);
    printf("El resultado es %d\n", r);
    return 0;
}

int suma(int a, int b){
    int result = a + b;
    return result;
}

