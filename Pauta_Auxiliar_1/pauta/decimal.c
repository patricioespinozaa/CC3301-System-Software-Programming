#include <math.h>

// 1001 = 9
// 2**0 + 2**3


int decimal(int binario){
    int result = 0;
    int i = 0;
    // Equivalente a (binario != 0)
    while(binario) {
        // módulo de 10, para ver la última cifra.
        if (binario%10)
            result += pow(2,i);
        binario /= 10;
        i++;
    }
    return result;
}
