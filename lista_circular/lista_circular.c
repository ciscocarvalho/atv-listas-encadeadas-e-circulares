#include "lista_circular.h"
#include <stdlib.h>

struct lista {
  int valor;
  struct lista *prox;
};

ListaCircular *buscar_ultimo(ListaCircular *primeiro) {
  if (primeiro == NULL) {
    return NULL;
  }

  ListaCircular *ultimo = primeiro;

  while (ultimo->prox != primeiro) {
    ultimo = ultimo->prox;
  }

  return ultimo;
}

ListaCircular *inserir(ListaCircular *primeiro, int valor) {
  ListaCircular *novo_primeiro = (ListaCircular *)malloc(sizeof(ListaCircular));

  if (primeiro == NULL) {
    novo_primeiro->prox = novo_primeiro;
  } else {
    ListaCircular *ultimo = buscar_ultimo(primeiro);
    ultimo->prox = novo_primeiro;
    novo_primeiro->prox = primeiro;
  }

  return novo_primeiro;
};

ListaCircular *buscar(ListaCircular *l, int valor) {
  if (l == NULL) {
    return NULL;
  }

  ListaCircular *aux = l;

  while (1) {
    if (aux->valor == valor) {
      return aux;
    } else if (aux->prox == l) {
      return NULL;
    }

    aux = aux->prox;
  }
};

ListaCircular *remover(ListaCircular *l, int valor) {
  ListaCircular *p = buscar(l, valor);

  if (p == NULL) {
    return l;
  }

  // A lista possui 1 elemento e ele foi achado, ao remove-lo a lista fica com
  // 0 (portanto, lista é NULL)
  if (l == l->prox) {
    free(p);
    return NULL;
  }

  l = p->prox;
  ListaCircular *ultimo = buscar_ultimo(p);
  ultimo->prox = l;

  free(p);

  return l;
};
