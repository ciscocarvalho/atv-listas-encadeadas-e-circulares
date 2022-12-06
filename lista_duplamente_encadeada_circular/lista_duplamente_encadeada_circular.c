#include "lista_duplamente_encadeada_circular.h"
#include <stdlib.h>

struct lista {
  int info;
  struct lista *prox;
  struct lista *ant;
};

ListaDuplamenteEncadeadaCircular *inserir(ListaDuplamenteEncadeadaCircular *l, int valor) {
  struct lista *novo = (ListaDuplamenteEncadeadaCircular *)malloc(sizeof(ListaDuplamenteEncadeadaCircular));
  novo->info = valor;

  if (l == NULL) {
    novo->prox = novo;
    novo->ant = novo;
  } else {
    novo->prox = l;
    l->ant = novo;
    novo->ant = l->ant;
    novo->ant->prox = novo;
  }

  return novo;
}

ListaDuplamenteEncadeadaCircular *buscar(ListaDuplamenteEncadeadaCircular *l, int valor) {
  if (l == NULL) {
    return NULL;
  }

  ListaDuplamenteEncadeadaCircular *aux = l;

  while (1) {
    if (aux->info == valor) {
      return aux;
    } else if (aux->prox == l) {
      return NULL;
    }

    aux = aux->prox;
  }
}

ListaDuplamenteEncadeadaCircular *remover(ListaDuplamenteEncadeadaCircular *l, int valor) {
  ListaDuplamenteEncadeadaCircular *p = buscar(l, valor);

  if (p == NULL) {
    return l;
  }

  // lista tem 1 elemento e ele foi achado
  if (p->ant == p) {
    free(p);
    return NULL;
  }

  l = p->prox;

  p->ant->prox = p->prox;
  p->prox->ant = p->ant;

  free(p);

  return l;
}
