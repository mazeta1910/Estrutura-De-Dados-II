void copiarEOrdenar(Lista* origem, Lista* destino) {
    if (origem == NULL || destino == NULL) return;

    // Percorre cada nó da lista origem
    struct no* atual = origem->inicio;
    while (atual != NULL) {
        // Insere o elemento na lista destino de forma ordenada
        inserirOrdenado(destino, atual->valor);
        atual = atual->prox;
    }
}

// Função auxiliar para inserir em ordem
void inserirOrdenado(Lista* l, int valor) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    novo->valor = valor;

    // Caso 1: lista vazia ou valor menor que o primeiro
    if (l->inicio == NULL || valor < l->inicio->valor) {
        novo->prox = l->inicio;
        l->inicio = novo;
        return;
    }

    // Caso 2: encontrar posição correta
    struct no* atual = l->inicio;
    while (atual->prox != NULL && atual->prox->valor < valor) {
        atual = atual->prox;
    }

    // Insere após o nó atual
    novo->prox = atual->prox;
    atual->prox = novo;
}
