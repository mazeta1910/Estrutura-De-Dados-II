#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "trocaCelulas.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    printf("=== FUNCAO trocaCelulas - Lista Duplamente Encadeada ===\n\n");

    Lista* lista = criaLista();

    // Criando lista inicial
    printf("=== CRIANDO LISTA INICIAL ===\n");
    insereLista(lista, 10, "A");
    insereLista(lista, 20, "B");
    insereLista(lista, 30, "C");
    insereLista(lista, 40, "D");
    insereLista(lista, 50, "E");

    printf("\nLista inicial:\n");
    imprimeLista(lista);
    imprimeListaReversa(lista);

    // Teste 1: Células não adjacentes
    printf("\n=== TESTE 1: Celulas nao adjacentes ===\n");
    trocaCelulas(lista, 10, 40);
    imprimeLista(lista);
    imprimeListaReversa(lista);

    // Teste 2: Células adjacentes
    printf("\n=== TESTE 2: Celulas adjacentes ===\n");
    trocaCelulas(lista, 20, 30);
    imprimeLista(lista);
    imprimeListaReversa(lista);

    // Teste 3: Primeira e última
    printf("\n=== TESTE 3: Primeira e ultima ===\n");
    trocaCelulas(lista, 40, 50);
    imprimeLista(lista);
    imprimeListaReversa(lista);

    // Teste 4: Casos de erro
    printf("\n=== TESTE 4: Casos de erro ===\n");
    trocaCelulas(lista, 20, 20); // Chaves iguais
    trocaCelulas(lista, 99, 20); // Chave inexistente

    // Menu interativo
    int opcao, chave1, chave2;
    char dados[100];

    do
    {
        printf("\n=== MENU ===\n");
        printf("1 - Inserir\n");
        printf("2 - Trocar celulas\n");
        printf("3 - Imprimir\n");
        printf("4 - Imprimir reversa\n");
        printf("5 - Remover\n");
        printf("6 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("Chave: ");
                scanf("%d", &chave1);
                printf("Dados: ");
                scanf(" %[^\n]", dados);
                insereLista(lista, chave1, dados);
                break;

            case 2:
                printf("Primeira chave: ");
                scanf("%d", &chave1);
                printf("Segunda chave: ");
                scanf("%d", &chave2);
                trocaCelulas(lista, chave1, chave2);
                break;

            case 3:
                imprimeLista(lista);
                break;

            case 4:
                imprimeListaReversa(lista);
                break;

            case 5:
                printf("Chave a remover: ");
                scanf("%d", &chave1);
                removeLista(lista, chave1);
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 6);

    liberaLista(lista);
    return 0;
}
