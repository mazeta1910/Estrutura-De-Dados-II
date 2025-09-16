#include <stdio.h>
#include <stdlib.h>
#include "pilha_separadora.h"

struct item
{
    int valor;
};

struct celula
{
    Item item;
    Celula *prox;
};

struct pilha
{
    Celula *topo;
};

Pilha* criaPilha()
{
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
    {
        pi->topo = NULL;
    }
    return pi;
}

int verificaPilhaVazia(Pilha* pi)
{
    return (pi->topo == NULL);
}

void empilha(Pilha* pi, int valor)
{
    Item novo;
    novo.valor = valor;
    
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = pi->topo;
    pi->topo = nova;
}

int desempilha(Pilha* pi)
{
    if(verificaPilhaVazia(pi))
    {
        printf("Erro: Pilha vazia!\n");
        return -1; // Valor de erro
    }
    
    Celula *remover = pi->topo;
    int valor = remover->item.valor;
    pi->topo = remover->prox;
    free(remover);
    
    return valor;
}

int topoPilha(Pilha* pi)
{
    if(verificaPilhaVazia(pi))
    {
        printf("Erro: Pilha vazia!\n");
        return -1; // Valor de erro
    }
    
    return pi->topo->item.valor;
}

// FUNÇÃO PRINCIPAL: Separa números pares e ímpares em pilhas diferentes
void separaParesImpares(Pilha* origem, Pilha* pares, Pilha* impares)
{
    if(verificaPilhaVazia(origem))
    {
        printf("Pilha origem esta vazia!\n");
        return;
    }
    
    printf("Separando numeros pares e impares...\n");
    
    // Pilha auxiliar para preservar a ordem original na pilha origem
    Pilha* auxiliar = criaPilha();
    
    // Desempilha todos os elementos da origem e processa
    while(!verificaPilhaVazia(origem))
    {
        int valor = desempilha(origem);
        
        // Empilha na auxiliar para preservar ordem
        empilha(auxiliar, valor);
        
        // Verifica se é par ou ímpar e empilha na pilha correspondente
        if(valor % 2 == 0)
        {
            empilha(pares, valor);
            printf("Numero %d (par) adicionado na pilha de pares\n", valor);
        }
        else
        {
            empilha(impares, valor);
            printf("Numero %d (impar) adicionado na pilha de impares\n", valor);
        }
    }
    
    // Restaura a pilha origem (opcional - mantém pilha original intacta)
    while(!verificaPilhaVazia(auxiliar))
    {
        int valor = desempilha(auxiliar);
        empilha(origem, valor);
    }
    
    liberaPilha(auxiliar);
    printf("Separacao concluida!\n");
}

void imprimePilha(Pilha* pi)
{
    if(verificaPilhaVazia(pi))
    {
        printf("Pilha vazia!\n");
        return;
    }
    
    Celula *aux = pi->topo;
    printf("Pilha (topo -> base): ");
    while(aux != NULL)
    {
        printf("%d ", aux->item.valor);
        aux = aux->prox;
    }
    printf("\n");
}

void liberaPilha(Pilha* pi)
{
    Celula *aux = pi->topo;
    Celula *liberar;
    while(aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(pi);
}

