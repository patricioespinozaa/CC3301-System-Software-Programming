#include "string.h" // necesario para funciones de str
#include <stdio.h>

// somos --> 0s 1o 2m 3o 4s <-> 4s 3o 2m 1o 0s --> somos
// hola --> 0h 1o 2l 3a <-> 3a 2l 1o 0h --> aloh
// strlen(hola) = 4 
int palindromo(char* s){
    char *p = s + strlen(s) - 1;
    while (s < p){
        if (*s != *p)
            return 0;       
        s++;
        p--;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    char test[] = "somos";
    char test2[] = "hola";

    int res1 = palindromo(test);
    printf("%s es un palindromo?: %d\n", test, res1);

    int res2 = palindromo(test2);
    printf("%s es un palindromo?: %d\n", test2, res2);
    
    return 0;
}
