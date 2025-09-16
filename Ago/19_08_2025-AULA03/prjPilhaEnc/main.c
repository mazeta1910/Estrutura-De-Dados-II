#include <stdio.h>
#include <stdlib.h>
#include "itemPilhaEnc.h"

int main()
{
    Pilha *p;
    int vazia, chave;

    printf("Criando pilha encadeada vazia.\n");
    p = criaPilhaVazia();

    vazia = verificaPilhaVazia(p);
    printf("Pilha vazia? %d", vazia);

    printf("\nAdicionando o 1o item:");
    chave = 1;
    empilha(p, chave);

    vazia = verificaPilhaVazia(p);
    printf("\nPilha vazia? %d", vazia);

    printf("\nAdicionando o 2o item:");
    chave = 2;
    empilha(p, chave);

    printf("\nAdicionando o 3o item:");
    chave = 3;
    empilha(p, chave);

    printf("\nAdicionando o 4o item:");
    chave = 4;
    empilha(p, chave);

    printf("\nAdicionando o 5o item:");
    chave = 5;
    empilha(p, chave);

    printf("\nAdicionando o 6o item:");
    chave = 6;
    empilha(p, chave);

    printf("\n\n\nItens da pilha:\n");
    imprimePilha(p);

    printf("\nRemovendo item do topo da pilha.\n");
    desempilha(p);
    imprimePilha(p);

    printf("\nRemovendo item do topo da pilha.\n");
    desempilha(p);
    imprimePilha(p);

    liberaPilha(p);

    return 0;
}
