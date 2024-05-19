#include <stdio.h>
#include <math.h> //compilar con -lm

int decimal(int binario){
    int result = 0;
    int i = 0;
    while(binario) {
        if (binario%10)
            result += pow(2,i);
        binario /= 10;
        i++;
    }
    return result;
}

int binario(int n){
    int result = 0;
    int i = 0;
    while(n) {
        if (n%2)
            result += pow(10,i);
        n /= 2;
        i++;
    }
    return result;
}


//0001 = 1

//1111 = -1

int main(){
    printf("1010 en decimal es %d, y decimal(1010)=%d\n", 0b1010, decimal(1010));
    
    printf("14 en decimal es %b, y binario(14)=%d\n", 14, binario(14));

    unsigned int x = 0b11011; // 0x1B
    unsigned int x2 = 0b001110;
    
    printf("aplicando %b & %b == %b\n", x, x2, x & x2);
    // 011011
    // 001110
    // &
    // 001010
    
    printf("aplicando %b | %b == %b\n", x, x2, x | x2);
    // 011011
    // 001110
    // |
    // 011111
    
    printf("aplicando %b ^ %b == %b\n", x, x2, x ^ x2);
    // 011011
    // 001110
    // ^
    // 010101
    
    printf("aplicando %b << %b == %b\n", x, 1, x << 1);
    // 011011
    // 1
    // <<
    // 110110
    
    printf("aplicando %b >> %b == %b\n", x, 1, x >> 1);
    // 011011
    // 1
    // >>
    // 001101
    
    printf("aplicando ~%b == %b\n", x, ~x);
    // ~011011
    // =
    // 1...100100
    
    printf("aplicando %b >> 2 == %b\n", ~x, (~x)>>2);
    // 1...100100
    // 2
    // >>
    // 1...111001
}

