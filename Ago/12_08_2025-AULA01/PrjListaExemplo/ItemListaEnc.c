#include <stdio.h>
#include <stdlib.h>

struct item{
    int chave;
};

struct celula {
    Item item;
    Celula *prox;
};

struct lista {
    Celula *primeira;
};

Lista * criaListaVazia() {
    Lista *lst = malloc(sizeof(Lista)); //alocar memória de forma dinâmica
    lst->primeira = NULL;
    return lst;
}

void imprimeLista(Lista *lst){
    Celula *aux;
    for (aux = lst->primeira; aux != NULL; aux = aux->prox)
    {
        printf("\nChave: %d \n", aux->item.chave);
    }
}

Celula *buscaPorChave(Lista *lst, int chave){
    Celula *aux = lst->primeira;
    while (aux != NULL && aux->item.chave != chave){
        aux = aux->prox;
    }
    return aux;
}

int verificaListaVazia(Lista *lst){
    return lst->primeira == NULL;
}

void insereInicioLista(Lista *lst, int chave){
    Item novo;
    novo.chave = chave;
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova ->prox = lst->primeira;
    lst->primeira = nova;
}

void insereFimLista(Lista *lst, int chave){
    Item novo;
    novo.chave = chave;
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    // Inserção no fim
    nova->prox = NULL;
    if (verificaListaVazia(lst))
    {
        //se a lista está vazia quem vai apontar para a nova é a primeira
        lst->primeira = nova;
    } else {
        //se não está vazia, quem vai apontar para aquela que
        //era a última
        Celula *ultima;
        ultima = lst->primeira;
        while (ultima -> prox != NULL){
            ultima = ultima->prox;
        }
        ultima -> prox = nova;
    }
}

void insereMeioLista(Lista *lst, int chave, int k){
    Celula *Aux = buscaPorChave(lst, x);
    if (aux != NULL){
        Item novo;
        novo.chave = chave;
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        nova->prox = aux->prox;
        aux-prox = nova;4}
    else
    {
        printf("\nO item informado não existe.");
    }
}

void liberaLista (lista *lst){
    Celula *aux = lst->primeira;
    Celula *liberar;
    while (aux!=NULL){
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(lst);
}
