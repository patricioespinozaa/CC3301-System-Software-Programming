#include <stdio.h>
#include <stdlib.h>

// 45 -> 3 3 5
// 45 % 3 = 0
// guardamos 3
// 15 % 3 = 0
// guardamos 3
// 5 % 5 

void factoresPrimos(int n){
    int factor = 2;
    while (factor <= n) {
        if (n%factor == 0){
            printf("%d ", factor);
            n /= factor;
        }
        else {
            factor++;
        }
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return -1;
    }
    int n = atoi(argv[1]);
    if (n==1)
        printf("1\n");
    else
        factoresPrimos(n);
}
