#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista_ordenada.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    // Criando as duas listas
    Lista* lista1 = criaLista();  // Lista com números
    Lista* lista2 = criaLista();  // Lista vazia (destino)
    
    printf("=== DEMONSTRACAO DA FUNCAO transfereOrdenado ===\n\n");
    
    // Populando a primeira lista com números desordenados
    printf("1. Populando a primeira lista com numeros desordenados:\n");
    insereLista(lista1, 15);
    insereLista(lista1, 3);
    insereLista(lista1, 8);
    insereLista(lista1, 1);
    insereLista(lista1, 12);
    insereLista(lista1, 5);
    insereLista(lista1, 20);
    insereLista(lista1, 7);
    
    printf("Lista 1 (origem): ");
    imprimeLista(lista1);
    printf("Lista 2 (destino): ");
    imprimeLista(lista2);
    
    printf("\n2. Executando transfereOrdenado(lista1, lista2):\n");
    transfereOrdenado(lista1, lista2);
    
    printf("\n3. Resultado apos a transferencia:\n");
    printf("Lista 1 (origem): ");
    imprimeLista(lista1);
    printf("Lista 2 (destino ordenado): ");
    imprimeLista(lista2);
    
    printf("\n=== TESTE COM LISTA VAZIA ===\n");
    Lista* lista3 = criaLista();  // Lista vazia
    Lista* lista4 = criaLista();  // Lista destino
    
    printf("Tentando transferir de lista vazia:\n");
    transfereOrdenado(lista3, lista4);
    
    printf("\n=== TESTE COM NUMEROS REPETIDOS ===\n");
    Lista* lista5 = criaLista();
    Lista* lista6 = criaLista();
    
    printf("Populando lista com numeros repetidos:\n");
    insereLista(lista5, 5);
    insereLista(lista5, 2);
    insereLista(lista5, 5);
    insereLista(lista5, 1);
    insereLista(lista5, 2);
    insereLista(lista5, 8);
    insereLista(lista5, 1);
    
    printf("Lista 5 (origem): ");
    imprimeLista(lista5);
    
    transfereOrdenado(lista5, lista6);
    
    printf("Lista 6 (destino ordenado): ");
    imprimeLista(lista6);
    
    // Liberando memória
    liberaLista(lista1);
    liberaLista(lista2);
    liberaLista(lista3);
    liberaLista(lista4);
    liberaLista(lista5);
    liberaLista(lista6);
    
    return 0;
}

