#include <stdio.h> //printf

typedef unsigned int uint;

// sizeof(type): función que entrega el tamaño en bytes.

int bits1(uint n){
    int k = 0;
    for (int i=0; i<sizeof(int)*8; i++){
        k += (n >> i) & 1;
    }
    return k;
}

// 000111010111 & 00...0111 = 111
// 001010010110 & 00...0111 = 110
// 000110110001 & 00...0111 = 001

int main(){
    uint n = 0b011001;
    printf("El numero esperado es 3 y el actual es %d\n",bits1(n));

    n = 0b00000000;
    printf("El numero esperado es 0 y el actual es %d\n",bits1(n));

    n = (uint) -1;
    printf("El numero esperado es 32 y el actual es %d\n",bits1(n));

    n = 0b10000000000000000000000000000;
    printf("El numero esperado es 1 y el actual es %d\n",bits1(n));

}
