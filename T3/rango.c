#include <stdio.h>
#include <stdlib.h>

#include "rango.h"

/*
typedef struct nodo {
  int x;             // un elemento del conjunto
  struct nodo *prox; // proximo nodo de la lista enlazada
} Nodo;
*/


void eliminarRango(Nodo **phead, double y, double z) {
    // si el nodo es una lista vacia
    if (*phead == NULL){
        return;
    }
    Nodo *head = *phead;
    // si cumple las condiciones, se elimina el nodo
    if ((y <= head->x)&&(head->x <= z)){
        Nodo *aux = head;
        *phead = head->prox;
        free(aux);
        eliminarRango(phead, y, z);
    }
    // si no cumple las condiciones, se mantiene el nodo
    else{
        eliminarRango(&(head->prox), y, z);
    }
    return;
}



