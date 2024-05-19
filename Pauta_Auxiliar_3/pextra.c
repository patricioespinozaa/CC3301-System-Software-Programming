#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char *copia(char *str) {
  //char res[ strlen(str)+1 ]; variable local, no retorna
  char *res = malloc( strlen(str)+1 );
  strcpy(res, str);
  return res;
}
int main( ) {
  char *r= copia("hola");
  printf("%s\n", r);
  r[0]= 'H';
  printf("%s\n", r);
  return 0;
}
