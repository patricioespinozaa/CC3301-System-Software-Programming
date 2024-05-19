#include <stdio.h>
typedef unsigned int uint;

// porque se puede aplicar tranquilamente shift right >>??
// Que pasa si hay 1 o 0???

// Si pensamos x como un arreglo de 32 posiciones, recorriendolo con una ventana
int posicionBits(uint x, uint p, int n){
    int m = ~(-1 << n);
    for (int i = 0; i<sizeof(int)*8-n+1; i++){
        uint ventana = ((x >> i) & m);
        if (ventana == p)
            return i;
    }
    return -1;
}

int main(){
    uint x = 0b0001110;
    uint p = 0b111;
    printf("El patron ocurre primero en la posicion 1 y obtenemos que ocurren en la posicion: %d\n",posicionBits(x,p,3));

    p = 0b0;
    printf("El patron ocurre primero en la posicion 0 y obtenemos que ocurren en la posicion: %d\n",posicionBits(x,p,1));

    p = 0b1111;
    printf("El patron ocurre no ocurre y obtenemos que: %d\n",posicionBits(x,p,4));

    uint a = 0b011;
    printf("El patron ocurre primero en la posicion 2 y obtenemos que ocurren en la posicion: %d\n",posicionBits(x,a,3));
}
