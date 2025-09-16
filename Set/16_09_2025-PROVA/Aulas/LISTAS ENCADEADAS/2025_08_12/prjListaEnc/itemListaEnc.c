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
    Lista *lst = malloc(sizeof(Lista)); //aloca mem�ria de forma din�mica
    lst->primeira = NULL;
    return lst;
}

void imprimeLista(Lista *lst) {
    Celula *aux;
    //Avan�a de c�lula em c�lula at� chegar na �ltima que aponta para NULL
    for (aux = lst->primeira; aux != NULL; aux = aux->prox)
    {
        printf("\nChave: %d\n", aux->item.chave);
        //Demais campos
    }
}

//retorna a celula do item com a chave procurada ou NULL se n�o encontrou
Celula * buscaPorChave(Lista *lst, int chave) {
    Celula *aux = lst->primeira;
    while (aux != NULL && aux->item.chave != chave)
    {
        aux = aux->prox;
    }
    return aux;
}

//retorna 1 se a lista est� vazia ou 0 se n�o est�
int verificaListaVazia(Lista *lst) {
    return lst->primeira == NULL;
}

void insereInicioLista(Lista *lst, int chave) {
    //Cria novo item que vai ser guardado na lista
    Item novo;
    novo.chave = chave;
    //Cria nova c�lula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    //Inser��o no in�cio: a pr�xima c�lula � aquela que era a primeira
    nova->prox = lst->primeira;
    //A primeira agora a � a nova c�lula
    lst->primeira = nova;
}

void insereFimLista(Lista *lst, int chave) {
    //Cria novo item que vai ser guardado na lista
    Item novo;
    novo.chave = chave;
    //Cria nova c�lula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    //Inser��o no fim
    nova->prox = NULL; //a nova c�lula vai ser a �ltima
    if (verificaListaVazia(lst))
    {
        //se a lista est� vazia, quem vai apontar para a nova � a primeira
        lst->primeira = nova;
    }
    else
    {
        //se n�o est� vazia, quem vai apontar para a nova � a que era �ltima
        Celula *ultima;
        ultima = lst->primeira;
        while (ultima ->prox != NULL) //localiza a �ltima c�lula
        {
            ultima = ultima->prox;
        }
        ultima->prox = nova; //ap�s a �ltima c�lula, insere a nova
    }
}

//Insere a nova chave ap�s a c�lula que cont�m a chave x
void insereMeioLista(Lista *lst, int chave, int x) {
    Celula *aux = buscaPorChave(lst, x);
    if (aux != NULL) {
        //Cria novo item que vai ser guardado na lista
        Item novo;
        novo.chave = chave;
        //Cria nova c�lula que vai guardar o item
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        //inser��o no meio
        nova->prox = aux->prox; //nova c�lula aponta para o endere�o apontado pela anterior
        aux->prox = nova; //c�lula anterior passa a apontar para a nova c�lula
    }
    else
    {
        printf("\nO item informado n�o existe. \n");
    }
}

void liberaLista(Lista *lst) {
    Celula *aux = lst->primeira;
    Celula *liberar;
    while (aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar); //Libera uma c�lula por vez
    }
    free(lst); //Libera a lista
}
