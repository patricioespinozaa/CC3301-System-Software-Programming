#include <stdio.h>
#include <stdint.h>

typedef uint64_t Decimal;

Decimal sumaDecimal(Decimal x, Decimal y){
    // 4 less significant bits mask
    Decimal res = 0;
    int carry = 0;
    for (int i=0; i<64; i++){
        Decimal bit_x = (x >> i) & ~((-1)<<i);
        Decimal bit_y = (y >> i) & ~((-1)<<i);
        Decimal bit_sum = bit_x + bit_y + carry;
        if (bit_sum > 1){
            carry = 1;
            bit_sum = 1;
        } else {
            carry = 0;
        }
        res = res | (bit_sum << i);
    }
    return res;
}

int main() {
    Decimal x = 0x37; // x en formato decimal
    Decimal y = 0x45; // y en formato decimal

    Decimal result = sumaDecimal(x, y); // Sumar x e y en formato decimal
    printf("Resultado: 0x%llx\n", result); // Imprimir el resultado en hexadecimal

    return 0;
}