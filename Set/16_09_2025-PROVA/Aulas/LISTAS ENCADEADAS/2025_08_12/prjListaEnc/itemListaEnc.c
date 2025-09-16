#include <stdio.h>
#include <stdlib.h>

struct item {
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
    Lista *lst = malloc(sizeof(Lista)); //aloca memória de forma dinâmica
    lst->primeira = NULL;
    return lst;
}

void imprimeLista(Lista *lst) {
    Celula *aux;
    //Avança de célula em célula até chegar na última que aponta para NULL
    for (aux = lst->primeira; aux != NULL; aux = aux->prox)
    {
        printf("\nChave: %d\n", aux->item.chave);
        //Demais campos
    }
}

//retorna a celula do item com a chave procurada ou NULL se não encontrou
Celula * buscaPorChave(Lista *lst, int chave) {
    Celula *aux = lst->primeira;
    while (aux != NULL && aux->item.chave != chave)
    {
        aux = aux->prox;
    }
    return aux;
}

//retorna 1 se a lista está vazia ou 0 se não está
int verificaListaVazia(Lista *lst) {
    return lst->primeira == NULL;
}

void insereInicioLista(Lista *lst, int chave) {
    //Cria novo item que vai ser guardado na lista
    Item novo;
    novo.chave = chave;
    //Cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    //Inserção no início: a próxima célula é aquela que era a primeira
    nova->prox = lst->primeira;
    //A primeira agora a é a nova célula
    lst->primeira = nova;
}

void insereFimLista(Lista *lst, int chave) {
    //Cria novo item que vai ser guardado na lista
    Item novo;
    novo.chave = chave;
    //Cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    //Inserção no fim
    nova->prox = NULL; //a nova célula vai ser a última
    if (verificaListaVazia(lst))
    {
        //se a lista está vazia, quem vai apontar para a nova é a primeira
        lst->primeira = nova;
    }
    else
    {
        //se não está vazia, quem vai apontar para a nova é a que era última
        Celula *ultima;
        ultima = lst->primeira;
        while (ultima ->prox != NULL) //localiza a última célula
        {
            ultima = ultima->prox;
        }
        ultima->prox = nova; //após a última célula, insere a nova
    }
}

//Insere a nova chave após a célula que contém a chave x
void insereMeioLista(Lista *lst, int chave, int x) {
    Celula *aux = buscaPorChave(lst, x);
    if (aux != NULL) {
        //Cria novo item que vai ser guardado na lista
        Item novo;
        novo.chave = chave;
        //Cria nova célula que vai guardar o item
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        //inserção no meio
        nova->prox = aux->prox; //nova célula aponta para o endereço apontado pela anterior
        aux->prox = nova; //célula anterior passa a apontar para a nova célula
    }
    else
    {
        printf("\nO item informado não existe. \n");
    }
}

void liberaLista(Lista *lst) {
    Celula *aux = lst->primeira;
    Celula *liberar;
    while (aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar); //Libera uma célula por vez
    }
    free(lst); //Libera a lista
}
