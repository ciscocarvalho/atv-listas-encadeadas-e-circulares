typedef struct lista ListaCircular;

ListaCircular *buscar_ultimo(ListaCircular *primeiro);

ListaCircular *inserir(ListaCircular *primeiro, int valor);

ListaCircular *buscar(ListaCircular *l, int valor);

ListaCircular *remover(ListaCircular *l, int valor);
