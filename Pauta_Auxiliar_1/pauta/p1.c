#include <stdio.h> // printf
#include <stdlib.h> // atois

// °F = °C * (9/5) + 32
// printf("23°C son %.1f°F\n", farenheit);

// printf("El factorial de 9 es %d\n", resultado);

// int argc, char* argv[], int num = atoi(argv[1]);

int factorial(int n);

int main(int argc, char* argv[]){
    float farenheit = 23.f * 9.f/5.f + 32.f;
    printf("23°C son %.1f°F\n", farenheit);
    
    int resultado = factorial(9);
    printf("El factorial de 9 es %d\n", resultado);
    
    if (argc != 2) {
        printf("Argumentos inválidos\n");
        return 0;
    }
    int n = atoi(argv[1]);
    int num = n;
    int resultado_iterativo = 1;
    while (n > 0) {
        resultado_iterativo *= n; // <=> x = x*n
        n--; // <=> n = n-1
    }
    printf("El factorial de %d es %d\n", num, resultado_iterativo);
    return 0;
}

int factorial(int n){
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n-1);
}

