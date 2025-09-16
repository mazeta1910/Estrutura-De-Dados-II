#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila_ordenada.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    printf("=== DEMONSTRACAO DA FUNCAO verificaFilaOrdenada ===\n\n");
    
    // TESTE 1: Fila ordenada crescente
    printf("=== TESTE 1: Fila ordenada crescente ===\n");
    Fila* fila1 = criaFilaVazia();
    
    enfileira(fila1, 1);
    enfileira(fila1, 3);
    enfileira(fila1, 5);
    enfileira(fila1, 7);
    enfileira(fila1, 9);
    
    imprimeFila(fila1);
    if(verificaFilaOrdenada(fila1))
    {
        printf("Resultado: ORDENADA (crescente)\n");
    }
    else
    {
        printf("Resultado: NAO ORDENADA\n");
    }
    
    // TESTE 2: Fila não ordenada
    printf("\n=== TESTE 2: Fila nao ordenada ===\n");
    Fila* fila2 = criaFilaVazia();
    
    enfileira(fila2, 5);
    enfileira(fila2, 2);
    enfileira(fila2, 8);
    enfileira(fila2, 1);
    enfileira(fila2, 9);
    
    imprimeFila(fila2);
    if(verificaFilaOrdenada(fila2))
    {
        printf("Resultado: ORDENADA (crescente)\n");
    }
    else
    {
        printf("Resultado: NAO ORDENADA\n");
    }
    
    // TESTE 3: Fila ordenada com elementos repetidos
    printf("\n=== TESTE 3: Fila ordenada com elementos repetidos ===\n");
    Fila* fila3 = criaFilaVazia();
    
    enfileira(fila3, 1);
    enfileira(fila3, 2);
    enfileira(fila3, 2);
    enfileira(fila3, 4);
    enfileira(fila3, 4);
    enfileira(fila3, 6);
    
    imprimeFila(fila3);
    if(verificaFilaOrdenada(fila3))
    {
        printf("Resultado: ORDENADA (crescente)\n");
    }
    else
    {
        printf("Resultado: NAO ORDENADA\n");
    }
    
    // TESTE 4: Fila ordenada decrescente (não deve ser considerada ordenada)
    printf("\n=== TESTE 4: Fila ordenada decrescente ===\n");
    Fila* fila4 = criaFilaVazia();
    
    enfileira(fila4, 9);
    enfileira(fila4, 7);
    enfileira(fila4, 5);
    enfileira(fila4, 3);
    enfileira(fila4, 1);
    
    imprimeFila(fila4);
    if(verificaFilaOrdenada(fila4))
    {
        printf("Resultado: ORDENADA (crescente)\n");
    }
    else
    {
        printf("Resultado: NAO ORDENADA (decrescente)\n");
    }
    
    // TESTE 5: Fila com um elemento
    printf("\n=== TESTE 5: Fila com um elemento ===\n");
    Fila* fila5 = criaFilaVazia();
    
    enfileira(fila5, 42);
    
    imprimeFila(fila5);
    if(verificaFilaOrdenada(fila5))
    {
        printf("Resultado: ORDENADA (um elemento)\n");
    }
    else
    {
        printf("Resultado: NAO ORDENADA\n");
    }
    
    // TESTE 6: Fila vazia
    printf("\n=== TESTE 6: Fila vazia ===\n");
    Fila* fila6 = criaFilaVazia();
    
    imprimeFila(fila6);
    if(verificaFilaOrdenada(fila6))
    {
        printf("Resultado: ORDENADA (fila vazia)\n");
    }
    else
    {
        printf("Resultado: NAO ORDENADA\n");
    }
    
    // TESTE 7: Fila com todos elementos iguais
    printf("\n=== TESTE 7: Fila com todos elementos iguais ===\n");
    Fila* fila7 = criaFilaVazia();
    
    enfileira(fila7, 5);
    enfileira(fila7, 5);
    enfileira(fila7, 5);
    enfileira(fila7, 5);
    
    imprimeFila(fila7);
    if(verificaFilaOrdenada(fila7))
    {
        printf("Resultado: ORDENADA (elementos iguais)\n");
    }
    else
    {
        printf("Resultado: NAO ORDENADA\n");
    }
    
    // TESTE 8: Fila quase ordenada (um elemento fora de lugar)
    printf("\n=== TESTE 8: Fila quase ordenada ===\n");
    Fila* fila8 = criaFilaVazia();
    
    enfileira(fila8, 1);
    enfileira(fila8, 2);
    enfileira(fila8, 5);  // Elemento fora de lugar
    enfileira(fila8, 3);
    enfileira(fila8, 4);
    
    imprimeFila(fila8);
    if(verificaFilaOrdenada(fila8))
    {
        printf("Resultado: ORDENADA (crescente)\n");
    }
    else
    {
        printf("Resultado: NAO ORDENADA (5 > 3)\n");
    }
    
    // Liberando memória
    liberaFila(fila1);
    liberaFila(fila2);
    liberaFila(fila3);
    liberaFila(fila4);
    liberaFila(fila5);
    liberaFila(fila6);
    liberaFila(fila7);
    liberaFila(fila8);
    
    return 0;
}

