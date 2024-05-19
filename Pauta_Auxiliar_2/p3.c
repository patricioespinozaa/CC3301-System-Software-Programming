#include <stdio.h>
typedef unsigned int uint;

// x = 001010_10110_101001
// val = 10001
// k = 5
// i = 6

//mascara1
// -1 = 0b11111111111111111111111111111111
// << k = 0b11111111111111111111111111100000
// ~() = 0b00000000000000000000000000011111
// x & mascara1 = últimos 5 bits de x

//mascara2
// mascara1 << i = 0b00000000000000000000011111000000
// x & mascara2 = 5 bits a la izquierda desde la posición i

// ~mascara2 = 0b11111111111111111111100000111111
uint repBits(uint x, int i, int k, uint val) {
    //maścara
    uint mascara1 = ~((-1) << k); // 0^{32-k}1^{k}
    uint mascara2 = mascara1 << i; // ej: k=3 i=2 -> m=0011100
    val <<= i; // val == val << i; 1111000
    // forma 1: apagando los bits a reemplazar y encendiendo 1's
    x &= ~mascara2;
    x |= val;
    
    // forma 2: dejando en 1 todos los bits a reemplazar y luego apagando los 0 del patrón
    //x |= mascara2;
    // sin esta mascara, se apagan los bits menos significativos.
    //uint mascara3 = ~((-1)<<i); 
    //x &= val + mascara3;
    
	return x;
}

int main() {
    uint x = 0b1110;
    printf("Llamando repBits(0b1110, 0, 4, 0b1010) deberia de dar 0b1010 = 10 y el valor que da es %d\n", repBits(x,0,4,0b1010));
    
    printf("Llamando repBits(0b1110, 0, 4, 0b1111) deberia de dar 0b1111 = 15 y el valor que da es %d\n", repBits(x,0,4,0b1111));
    
    printf("Llamando repBits(0b1110, 4, 4, 0b1111) deberia de dar 0b11111110 = 254 y el valor que da es %d\n", repBits(x,4,4,0b1111));
    
    printf("Llamando repBits(0b1110, 1, 3, 0b0) deberia de dar 0b0 = 0 y el valor que da es %d\n", repBits(x,1,3,0b0));
}
