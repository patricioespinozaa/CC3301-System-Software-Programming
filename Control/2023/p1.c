#include <stdio.h>
#include <stdint.h>

typedef unsigned int uint;

int palindrome(uint x){
    // Initialize variables
    int is_palindrome = 1; // Assume palindrome
    uint mask = 0xF0000000; // Mask for the most significant nibble

    // Iterate through the nibbles
    for (int i = 0; i < 4; i++) {
        uint left_nibble = (x & mask) >> (28 - 4 * i); // Get the left nibble
        uint right_nibble = (x << (28 - 4 * i)) >> 28; // Get the corresponding right nibble

        if (left_nibble != right_nibble) { // Check if they are equal
            is_palindrome = 0; // Not a palindrome
            break; // Exit loop
        }
        mask >>= 4; // Shift the mask for the next iteration
    }
    return is_palindrome;
}

int main() {
    int rc1 = palindrome(0x3a0ff0a3); // Debería devolver 1, es palíndromo
    int rc2 = palindrome(0x3a0ff0a4); // Debería devolver 0, no es palíndromo
    int rc3 = palindrome(0x3a0fe0b3); // Debería devolver 0
    int rc4 = palindrome(0x11); // Debería devolver 0, 0x11 es equivalente a 0x00000011

    printf("rc1: %d\n", rc1);
    printf("rc2: %d\n", rc2);
    printf("rc3: %d\n", rc3);
    printf("rc4: %d\n", rc4);

    return 0;
}