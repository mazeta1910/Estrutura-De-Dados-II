#include <stdio.h>
#include <stdlib.h>
#include "itemPilhaEnc.h"

struct item {
    int chave;
    //Demais campos
};

struct celula {
    Item item;
    Celula *prox;
};

struct pilha {
    Celula *topo;
};

Pilha *criaPilhaVazia() {
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void empilha(Pilha *p, int chave) {
    //Cria novo item que vai ser guardado na pilha
    Item novo;
    novo.chave = chave;
    //Cria nova celula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = p->topo;
    p->topo = nova;
}

void imprimePilha(Pilha *p) {
    Celula *aux;
    for (aux = p->topo; aux != NULL; aux = aux->prox)
    {
        printf("Chave: %d\n", aux->item.chave);
    }
}

void desempilha(Pilha *p) {
    if (verificaPilhaVazia(p))
    {
        printf("Erro: pilha vazia.\n");
        return;
    }
    Celula *remover = p->topo; //sempre remove a célula do topo
    p->topo = remover->prox; //atualiza a informação de quem é o novo topo
    free(remover); //libera a célula da memória
}

//retorna 1 se a pilha está vazia ou 0 se não está
int verificaPilhaVazia(Pilha *p) {
    return p->topo == NULL;
}

void liberaPilha(Pilha *p) {
    Celula *aux = p->topo;
    Celula *liberar;
    while (aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(p);
}

