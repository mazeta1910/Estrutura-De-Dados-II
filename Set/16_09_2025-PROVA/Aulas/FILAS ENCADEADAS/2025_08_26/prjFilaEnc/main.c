#include <stdio.h>
#include <stdlib.h>
#include "itemFilaEnc.h"

int main()
{
    Fila *f;
    int vazia, chave;

    printf("Criando fila encadeada vazia.\n");
    f = criaFilaVazia();
    vazia = verificaFilaVazia(f);
    printf("Fila vazia?%d\n", vazia);

    printf("\nAdicionando o 1o item.\n");
    chave = 1;
    enfileira(f, chave);

    vazia = verificaFilaVazia(f);
    printf("Fila vazia?%d\n", vazia);

    printf("\nAdicionando o 2o item.\n");
    chave = 2;
    enfileira(f, chave);

    printf("\nAdicionando o 3o item.\n");
    chave = 3;
    enfileira(f, chave);

    printf("\nAdicionando o 4o item.\n");
    chave = 4;
    enfileira(f, chave);

    printf("\nAdicionando o 5o item.\n");
    chave = 5;
    enfileira(f, chave);

    printf("\nAdicionando o 6o item.\n");
    chave = 6;
    enfileira(f, chave);

    printf("\nItens da fila:\n");
    imprimeFila(f);

    printf("\nRemovendo primeiro item da fila.\n");
    desenfileira(f);
    imprimeFila(f);

    printf("\nRemovendo primeiro item da fila.\n");
    desenfileira(f);
    imprimeFila(f);

    liberaFila(f);
    return 0;
}
