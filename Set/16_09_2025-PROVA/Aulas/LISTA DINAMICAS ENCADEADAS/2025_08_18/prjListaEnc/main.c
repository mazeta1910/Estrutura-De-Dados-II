#include <stdio.h>
#include <stdlib.h>
#include "itemListaEnc.h"

int main()
{
    Lista *lst;
    int vazia, chave;

    printf("Criado lista vazia.");
    lst = criaListaVazia();

    vazia = verificaListaVazia(lst);
    printf("\nLista vazia? %d\n", vazia);

    printf("\nAdicionando o 1o item no inicio.\n");
    chave = 1;
    insereInicioLista(lst, chave);

    vazia = verificaListaVazia(lst);
    printf("Lista vazia? %d\n", vazia);

    printf("\nAdicionando o 2o item no fim.\n");
    chave = 2;
    insereFimLista(lst, chave);

    printf("\nAdicionando o 3o item no meio.\n");
    chave = 3;
    insereMeioLista(lst, chave, 1);

    printf("\nAdicionando o 4o item no fim.\n");
    chave = 4;
    insereFimLista(lst, chave);

    printf("\nAdicionando o 5o item no início.\n");
    chave = 5;
    insereInicioLista(lst, chave);

    printf("\nAdicionando o 6o item no início.\n");
    chave = 6;
    insereInicioLista(lst, chave);

    printf("\nItens da lista:\n");
    imprimeLista(lst);

    printf("\nRemovendo o item com chave = 6\n");
    removeItem(lst, 6);
    imprimeLista(lst);

    printf("\nTentando remover o item com chave = 7\n");
    removeItem(lst, 7);
    imprimeLista(lst);

    liberaLista(lst);

    return 0;
}
