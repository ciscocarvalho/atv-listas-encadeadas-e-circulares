#include "lista_duplamente_encadeada.h"
#include <stdlib.h>

struct lista {
  int info;
  struct lista *prox;
  struct lista *ant;
};

// É responsabilidade do caller garantir que a lista passada nao é uma lista
// duplamente encadeada *circular*, se for e lista != NULL, o retorno também
// será uma lista duplamente encadeada circular
ListaDuplamenteEncadeada *inserir(ListaDuplamenteEncadeada *l, int valor) {
  struct lista *novo = (ListaDuplamenteEncadeada *)malloc(sizeof(ListaDuplamenteEncadeada));
  novo->info = valor;
  novo->prox = l;

  if (l == NULL) {
    novo->ant = NULL;
  } else {
    novo->ant = l->ant;
    l->ant = novo;
    if (novo->ant != NULL) {
      novo->ant->prox = novo;
    }
  }

  return novo;
}

ListaDuplamenteEncadeada *buscar(ListaDuplamenteEncadeada *l, int valor) {
  if (l == NULL) {
    return NULL;
  }

  ListaDuplamenteEncadeada *aux = l;

  while (1) {
    if (aux->info == valor) {
      return aux;
    } else if (aux->prox == NULL) {
      return NULL;
    }

    aux = aux->prox;
  }
}

ListaDuplamenteEncadeada *remover(ListaDuplamenteEncadeada *l, int valor) {
  ListaDuplamenteEncadeada *p = buscar(l, valor);

  if (p == NULL) {
    return l;
  }

  // lista tem 1 elemento e ele foi achado
  if (p->ant == NULL && p->prox == NULL) {
    free(p);
    return NULL;
  }

  l = p->prox;

  p->ant->prox = p->prox;
  p->prox->ant = p->ant;

  free(p);

  return l;
}
