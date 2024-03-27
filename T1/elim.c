#include <stdio.h>
#include <stdint.h>

#include "elim.h"

uint64_t elimHex(uint64_t x, int h) {
  // new x without h matches
  uint64_t nx = 0;
  // using a 4 less important bits mask (1 digit)  (0b1111)
  uint64_t m = ~( (uint64_t)-1 << 4);
  // allows to take acount of the digit position we are working with
  int shift = 0;
  // iteration through x searching for h
  for (int i=0; i<16; i++){
    // x 4 less important bits 
    uint64_t value = x & m;
    // if it matches we wil ignore it, other case we will add it to the new x
    if (value != h) { 
      nx = nx | (value << shift);
      shift += 4;
    }
    // shift x 4 bits to get next value
    x = x >> 4;
  }
  return nx;
}

/*
int main(){
  uint64_t rc1= elimHex(0x3a0ff0a3, 3); // rc1 es 0x00a0ff0a : 10551050
  uint64_t rc2= elimHex(0x3a0ff0a4, 0); // rc2 es 0x003affa4 : 3866532
  uint64_t rc3= elimHex(0x3a0fe0b3, 0xf); // rc3 es 0x03a0e0b3: 60874931
  uint64_t rc4= elimHex(0x3a0fe0b3, 0xd); // rc3 es 0x3a0fe0b3: 974119091

  int m = 1 << 2;
  printf("1<<2: %d\n", m);
  printf("rc1 debe ser 10551050 y el resultado fue: %d\n", rc1);
  printf("rc2 debe ser 3866532 y el resultado fue: %d\n", rc2);
  printf("rc3 debe ser 60874931 y el resultado fue: %d\n", rc3);
  printf("rc3 debe ser 974119091 y el resultado fue: %d\n", rc4);
}
*/
