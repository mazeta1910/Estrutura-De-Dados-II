#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha_separadora.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    printf("=== DEMONSTRACAO DA FUNCAO separaParesImpares ===\n\n");
    
    // Criando as três pilhas
    Pilha* pilhaOrigem = criaPilha();   // Pilha com números
    Pilha* pilhaPares = criaPilha();    // Pilha vazia (destino pares)
    Pilha* pilhaImpares = criaPilha();  // Pilha vazia (destino ímpares)
    
    // Populando a pilha origem com números variados
    printf("1. Populando a pilha origem com numeros:\n");
    empilha(pilhaOrigem, 15);  // ímpar
    empilha(pilhaOrigem, 8);   // par
    empilha(pilhaOrigem, 3);   // ímpar
    empilha(pilhaOrigem, 12);  // par
    empilha(pilhaOrigem, 7);   // ímpar
    empilha(pilhaOrigem, 20);  // par
    empilha(pilhaOrigem, 1);   // ímpar
    empilha(pilhaOrigem, 6);   // par
    
    printf("Pilha Origem: ");
    imprimePilha(pilhaOrigem);
    printf("Pilha Pares: ");
    imprimePilha(pilhaPares);
    printf("Pilha Impares: ");
    imprimePilha(pilhaImpares);
    
    printf("\n2. Executando separaParesImpares(origem, pares, impares):\n");
    separaParesImpares(pilhaOrigem, pilhaPares, pilhaImpares);
    
    printf("\n3. Resultado apos a separacao:\n");
    printf("Pilha Origem: ");
    imprimePilha(pilhaOrigem);
    printf("Pilha Pares: ");
    imprimePilha(pilhaPares);
    printf("Pilha Impares: ");
    imprimePilha(pilhaImpares);
    
    printf("\n=== TESTE COM PILHA VAZIA ===\n");
    Pilha* pilhaVazia = criaPilha();
    Pilha* pilhaParesVazia = criaPilha();
    Pilha* pilhaImparesVazia = criaPilha();
    
    printf("Tentando separar de pilha vazia:\n");
    separaParesImpares(pilhaVazia, pilhaParesVazia, pilhaImparesVazia);
    
    printf("\n=== TESTE COM APENAS PARES ===\n");
    Pilha* pilhaSoPares = criaPilha();
    Pilha* pilhaDestinoPares = criaPilha();
    Pilha* pilhaDestinoImpares = criaPilha();
    
    printf("Populando pilha apenas com numeros pares:\n");
    empilha(pilhaSoPares, 2);
    empilha(pilhaSoPares, 4);
    empilha(pilhaSoPares, 6);
    empilha(pilhaSoPares, 8);
    
    printf("Pilha com so pares: ");
    imprimePilha(pilhaSoPares);
    
    separaParesImpares(pilhaSoPares, pilhaDestinoPares, pilhaDestinoImpares);
    
    printf("Resultado:\n");
    printf("Pilha Pares: ");
    imprimePilha(pilhaDestinoPares);
    printf("Pilha Impares: ");
    imprimePilha(pilhaDestinoImpares);
    
    printf("\n=== TESTE COM APENAS IMPARES ===\n");
    Pilha* pilhaSoImpares = criaPilha();
    Pilha* pilhaDestinoPares2 = criaPilha();
    Pilha* pilhaDestinoImpares2 = criaPilha();
    
    printf("Populando pilha apenas com numeros impares:\n");
    empilha(pilhaSoImpares, 1);
    empilha(pilhaSoImpares, 3);
    empilha(pilhaSoImpares, 5);
    empilha(pilhaSoImpares, 7);
    
    printf("Pilha com so impares: ");
    imprimePilha(pilhaSoImpares);
    
    separaParesImpares(pilhaSoImpares, pilhaDestinoPares2, pilhaDestinoImpares2);
    
    printf("Resultado:\n");
    printf("Pilha Pares: ");
    imprimePilha(pilhaDestinoPares2);
    printf("Pilha Impares: ");
    imprimePilha(pilhaDestinoImpares2);
    
    // Liberando memória
    liberaPilha(pilhaOrigem);
    liberaPilha(pilhaPares);
    liberaPilha(pilhaImpares);
    liberaPilha(pilhaVazia);
    liberaPilha(pilhaParesVazia);
    liberaPilha(pilhaImparesVazia);
    liberaPilha(pilhaSoPares);
    liberaPilha(pilhaDestinoPares);
    liberaPilha(pilhaDestinoImpares);
    liberaPilha(pilhaSoImpares);
    liberaPilha(pilhaDestinoPares2);
    liberaPilha(pilhaDestinoImpares2);
    
    return 0;
}

