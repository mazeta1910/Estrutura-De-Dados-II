#include <stdio.h>
#include <stdlib.h>
#include "itemFilaEnc.h"

struct item {
    int chave;
    //Demais campos
};

struct celula {
    Item item;
    Celula *prox;
};

struct fila {
    Celula *ini;
    Celula *fim;
};

Fila *criaFilaVazia() {
    Fila *f = malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

void enfileira(Fila *f, int chave) {
    //Cria novo item que vai ser guardado na fila
    Item novo;
    novo.chave = chave;
    //Cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = NULL;
    if (verificaFilaVazia(f))
    {
        f->ini = nova; //Se está vazia adiciona no início
    }
    else
    {
        f->fim->prox = nova;
    }
    f->fim = nova; //enfileira sempre a célula que será a última
}

void imprimeFila(Fila *f) {
    Celula *aux = f->ini;
    while (aux != NULL)
    {
        printf("Chave: %d\n", aux->item.chave);
        aux = aux->prox;
    }
}

void desenfileira(Fila *f) {
    if (verificaFilaVazia(f))
    {
        printf("Erro: Fila vazia!.\n");
        return;
    }
    Celula *remover = f->ini;
    f->ini = remover->prox;
    free(remover);
    if (verificaFilaVazia(f)) //Se ficou vazia...
    {
        f->fim = NULL; //não há mais célula no fim
    }
}

//retorna 1 se a fila está vazia, ou 0 se não está
int verificaFilaVazia(Fila *f) {
    return f->ini == NULL;
}

void liberaFila(Fila *f) {
    Celula *aux = f->ini;
    Celula *liberar;
    while (aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(f);
}
