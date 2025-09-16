void insereOrdenado(Lista* li, int chave, char* dados)
{
    // Cria novo item
    Item novo;
    novo.chave = chave;
    strcpy(novo.dados, dados);

    // Cria nova célula
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;

    // CASO 1: Lista vazia
    if(verificaListaVazia(li))
    {
        nova->ant = NULL;
        nova->prox = NULL;
        li->ini = nova;
        li->fim = nova;
        printf("Item %d inserido em lista vazia.\n", chave);
        return;
    }

    // CASO 2: Inserir no início (menor que o primeiro)
    if(chave < li->ini->item.chave)
    {
        nova->ant = NULL;
        nova->prox = li->ini;
        li->ini->ant = nova;
        li->ini = nova;
        printf("Item %d inserido no inicio.\n", chave);
        return;
    }

    // CASO 3: Inserir no fim (maior que o último)
    if(chave > li->fim->item.chave)
    {
        nova->ant = li->fim;
        nova->prox = NULL;
        li->fim->prox = nova;
        li->fim = nova;
        printf("Item %d inserido no fim.\n", chave);
        return;
    }

    // CASO 4: Inserir no meio (encontrar posição correta)
    Celula *aux = li->ini;
    while(aux != NULL && aux->item.chave < chave)
    {
        aux = aux->prox;
    }

    // Inserir nova célula antes de aux
    nova->ant = aux->ant;
    nova->prox = aux;
    aux->ant->prox = nova;
    aux->ant = nova;

    printf("Item %d inserido no meio da lista.\n", chave);
}
