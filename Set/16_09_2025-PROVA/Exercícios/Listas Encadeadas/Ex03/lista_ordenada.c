#include <stdio.h>
#include <stdlib.h>
#include "lista_ordenada.h"

struct item
{
    int valor;
};

struct celula
{
    Item item;
    Celula *prox;
};

struct lista
{
    Celula *ini;
};

Lista* criaLista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
    {
        li->ini = NULL;
    }
    return li;
}

int verificaListaVazia(Lista* li)
{
    return (li->ini == NULL);
}

// Inserção simples no início (para popular a lista origem)
void insereLista(Lista* li, int valor)
{
    Item novo;
    novo.valor = valor;
    
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = li->ini;
    li->ini = nova;
}

// Inserção ordenada (crescente)
void insereOrdenado(Lista* li, int valor)
{
    Item novo;
    novo.valor = valor;
    
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    
    // Se lista vazia ou valor menor que o primeiro
    if(verificaListaVazia(li) || valor < li->ini->item.valor)
    {
        nova->prox = li->ini;
        li->ini = nova;
        return;
    }
    
    // Procura posição correta para inserir
    Celula *atual = li->ini;
    while(atual->prox != NULL && atual->prox->item.valor < valor)
    {
        atual = atual->prox;
    }
    
    // Insere na posição encontrada
    nova->prox = atual->prox;
    atual->prox = nova;
}

// FUNÇÃO PRINCIPAL: Transfere elementos de uma lista para outra de forma ordenada
void transfereOrdenado(Lista* origem, Lista* destino)
{
    if(verificaListaVazia(origem))
    {
        printf("Lista origem esta vazia!\n");
        return;
    }
    
    printf("Transferindo elementos de forma ordenada...\n");
    
    Celula *aux = origem->ini;
    while(aux != NULL)
    {
        insereOrdenado(destino, aux->item.valor);
        aux = aux->prox;
    }
    
    printf("Transferencia concluida!\n");
}

void imprimeLista(Lista* li)
{
    if(verificaListaVazia(li))
    {
        printf("Lista vazia!\n");
        return;
    }
    
    Celula *aux = li->ini;
    printf("Lista: ");
    while(aux != NULL)
    {
        printf("%d ", aux->item.valor);
        aux = aux->prox;
    }
    printf("\n");
}

void liberaLista(Lista* li)
{
    Celula *aux = li->ini;
    Celula *liberar;
    while(aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(li);
}

