#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct nodo {
 int x;
 struct nodo *izq, *der;
 struct nodo *prev, *prox;
} Nodo;

void asignarPrev(Nodo *t, Nodo **pprev) {
  if (t == NULL){                         // Caso en que es nulo
    return;
  }
  else{
    asignarPrev(t->izq, pprev);           // Recorre arbol izquierdo

    // Proceso en el nodo T
    t -> prev = *pprev;                   // Cuando visite el nodo T, su nodo previo es *pprev.
    t -> prox = NULL;                     // Asigne NULL a su nodo próximo por ahora.
    if (t -> prev != NULL){               // Si el nodo previo a T no es NULL
      (t -> prev) -> prox = t;            // T es el nodo próximo del nodo previo a T
    }
    *pprev = t;                           // Antes de continuar el recorrido, asigne T a *pprev.
    asignarPrev(t->der, pprev);           // Recorre arbol derecho
  }
}
