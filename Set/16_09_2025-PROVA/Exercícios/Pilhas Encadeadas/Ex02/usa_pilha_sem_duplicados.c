#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha_sem_duplicados.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    printf("=== DEMONSTRACAO DA FUNCAO removeDuplicados ===\n\n");
    
    // TESTE 1: Exemplo fornecido no exercício
    printf("=== TESTE 1: Exemplo do exercicio ===\n");
    Pilha* pilha1 = criaPilha();
    
    // Empilhando na ordem inversa para obter: 0, 1, 2, 2, 3, 4, 8, 9, 9 (topo -> base)
    empilha(pilha1, 9);  // base
    empilha(pilha1, 9);
    empilha(pilha1, 8);
    empilha(pilha1, 4);
    empilha(pilha1, 3);
    empilha(pilha1, 2);
    empilha(pilha1, 2);
    empilha(pilha1, 1);
    empilha(pilha1, 0);  // topo
    
    printf("Pilha inicial: ");
    imprimePilha(pilha1);
    
    removeDuplicados(pilha1);
    
    printf("Pilha sem duplicados: ");
    imprimePilha(pilha1);
    
    // TESTE 2: Pilha com muitos duplicados
    printf("\n=== TESTE 2: Pilha com muitos duplicados ===\n");
    Pilha* pilha2 = criaPilha();
    
    empilha(pilha2, 5);
    empilha(pilha2, 3);
    empilha(pilha2, 5);
    empilha(pilha2, 1);
    empilha(pilha2, 3);
    empilha(pilha2, 1);
    empilha(pilha2, 5);
    empilha(pilha2, 1);
    
    printf("Pilha inicial: ");
    imprimePilha(pilha2);
    
    removeDuplicados(pilha2);
    
    printf("Pilha sem duplicados: ");
    imprimePilha(pilha2);
    
    // TESTE 3: Pilha sem duplicados
    printf("\n=== TESTE 3: Pilha sem duplicados ===\n");
    Pilha* pilha3 = criaPilha();
    
    empilha(pilha3, 7);
    empilha(pilha3, 5);
    empilha(pilha3, 3);
    empilha(pilha3, 1);
    
    printf("Pilha inicial: ");
    imprimePilha(pilha3);
    
    removeDuplicados(pilha3);
    
    printf("Pilha sem duplicados: ");
    imprimePilha(pilha3);
    
    // TESTE 4: Pilha com todos elementos iguais
    printf("\n=== TESTE 4: Todos elementos iguais ===\n");
    Pilha* pilha4 = criaPilha();
    
    empilha(pilha4, 7);
    empilha(pilha4, 7);
    empilha(pilha4, 7);
    empilha(pilha4, 7);
    empilha(pilha4, 7);
    
    printf("Pilha inicial: ");
    imprimePilha(pilha4);
    
    removeDuplicados(pilha4);
    
    printf("Pilha sem duplicados: ");
    imprimePilha(pilha4);
    
    // TESTE 5: Pilha com um elemento
    printf("\n=== TESTE 5: Pilha com um elemento ===\n");
    Pilha* pilha5 = criaPilha();
    
    empilha(pilha5, 42);
    
    printf("Pilha inicial: ");
    imprimePilha(pilha5);
    
    removeDuplicados(pilha5);
    
    printf("Pilha sem duplicados: ");
    imprimePilha(pilha5);
    
    // TESTE 6: Pilha vazia
    printf("\n=== TESTE 6: Pilha vazia ===\n");
    Pilha* pilha6 = criaPilha();
    
    printf("Pilha inicial: ");
    imprimePilha(pilha6);
    
    removeDuplicados(pilha6);
    
    printf("Pilha sem duplicados: ");
    imprimePilha(pilha6);
    
    // Liberando memória
    liberaPilha(pilha1);
    liberaPilha(pilha2);
    liberaPilha(pilha3);
    liberaPilha(pilha4);
    liberaPilha(pilha5);
    liberaPilha(pilha6);
    
    return 0;
}

