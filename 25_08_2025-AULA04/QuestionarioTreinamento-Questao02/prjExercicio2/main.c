#include <stdio.h>
#include <stdlib.h>
#include "prjQuestao02.h"

int main() {
    // Cria duas listas
    Lista* lista1 = criarLista();
    Lista* lista2 = criarLista();

    // Insere elementos na primeira lista
    listaInserirFim(lista1, 10);
    listaInserirFim(lista1, 20);
    listaInserirFim(lista1, 30);

    // Insere elementos na segunda lista
    listaInserirFim(lista2, 40);
    listaInserirFim(lista2, 50);
    listaInserirFim(lista2, 60);

    // Imprime as listas originais
    printf("Antes da concatenacao:\n");
    listaImprimir(lista1);
    listaImprimir(lista2);

    // Concatena lista2 no final de lista1
    listaConcatenar(lista1, lista2);

    // Imprime o resultado
    printf("\nDepois da concatenacao:\n");
    listaImprimir(lista1);
    listaImprimir(lista2);  // lista2 deve estar vazia

    // Libera a memória
    listaLiberar(lista1);
    listaLiberar(lista2);

    return 0;
}
