#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

// Node structure
typedef struct {
  int izq, der;
  short tam_llave, tam_valor;
} NodoArch;

typedef struct nodo {
  intptr_t pos;
  char *llave, *valor;
  struct nodo *pizq, *pder;
  NodoArch nodoa;
} Nodo;

int main(int argc, char **argv) {
  // Right number of arguments
  if (argc != 3) {
    fprintf(stderr, "uso: ./consultar.bin <archivo> <llave>\n");
    exit(1);
  }
  // Open file
  char *nomArch = argv[1];
  char *llave = argv[2];
  FILE *f = fopen(nomArch, "r"); 
  // File was opened and exists
  if (f == NULL) {
    perror(nomArch);
    exit(2);
  }

  // Store the current node information
  NodoArch CurrentNode;
  int offset = 0;                                     // Current node offset
  int found = 0;                                      // Indicates if the key was found

  while (!found && offset != -1) {                    // While the key was not found and there are nodes to read
    fseek(f, offset, SEEK_SET);                       // Move the file pointer to the current node
    fread(&CurrentNode, sizeof(NodoArch), 1, f);      // Read the current node
    char buff_key[CurrentNode.tam_llave+1];           // Creates a buffer to store the key
    fread(buff_key, CurrentNode.tam_llave, 1, f);     // Read the node key 
    buff_key[CurrentNode.tam_llave] = '\0';           // Adds the null terminator
    int cmp = strcmp(llave, buff_key);                // Compares the key with the current key
    // Key was found
    if (cmp == 0) { 
      found = 1; 
      char buff_value[CurrentNode.tam_valor+1];       // Creates a buffer to store the definition
      fread(buff_value, CurrentNode.tam_valor, 1, f); // Reads the definition
      buff_value[CurrentNode.tam_valor] = '\0';       // Adds the null terminator
      printf("%s\n", buff_value);                     // Print the definition
      return 0; 
    } else if (cmp < 0) {                             // If the searched key is smaller, go to the left subtree
      offset = CurrentNode.izq;
    } else {                                          // If the searched key is bigger, go to the right subtree
      offset = CurrentNode.der;
    }
  }
  // Key was not found
  fprintf(stderr, "La llave %s no existe\n", argv[2]);
  fclose(f);     
  exit(3);     
  return 0; 
}