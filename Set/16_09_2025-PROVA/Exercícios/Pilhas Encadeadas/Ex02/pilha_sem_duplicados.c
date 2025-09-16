#include <stdio.h>
#include <stdlib.h>
#include "pilha_sem_duplicados.h"

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

// Função auxiliar: verifica se um valor já existe na pilha
int existeNaPilha(Pilha* pi, int valor)
{
    if(verificaPilhaVazia(pi))
    {
        return 0; // Não existe
    }
    
    // Pilha temporária para preservar a pilha original
    Pilha* temp = criaPilha();
    int encontrado = 0;
    
    // Desempilha todos os elementos procurando o valor
    while(!verificaPilhaVazia(pi))
    {
        int elemento = desempilha(pi);
        empilha(temp, elemento);
        
        if(elemento == valor)
        {
            encontrado = 1;
        }
    }
    
    // Restaura a pilha original
    while(!verificaPilhaVazia(temp))
    {
        int elemento = desempilha(temp);
        empilha(pi, elemento);
    }
    
    liberaPilha(temp);
    return encontrado;
}

// FUNÇÃO PRINCIPAL: Remove duplicados manipulando apenas o topo
void removeDuplicados(Pilha* pilhaOriginal)
{
    if(verificaPilhaVazia(pilhaOriginal))
    {
        printf("Pilha esta vazia!\n");
        return;
    }
    
    printf("Removendo duplicados da pilha...\n");
    
    Pilha* pilhaAuxiliar = criaPilha();  // Pilha para elementos únicos
    
    // Processa cada elemento da pilha original
    while(!verificaPilhaVazia(pilhaOriginal))
    {
        int valor = desempilha(pilhaOriginal);
        
        // Verifica se o valor já existe na pilha auxiliar
        if(!existeNaPilha(pilhaAuxiliar, valor))
        {
            empilha(pilhaAuxiliar, valor);
            printf("Valor %d mantido (primeira ocorrencia)\n", valor);
        }
        else
        {
            printf("Valor %d removido (duplicado)\n", valor);
        }
    }
    
    // Transfere elementos únicos de volta para a pilha original
    // (isso inverte a ordem, então precisamos inverter novamente)
    Pilha* pilhaTemp = criaPilha();
    
    while(!verificaPilhaVazia(pilhaAuxiliar))
    {
        int valor = desempilha(pilhaAuxiliar);
        empilha(pilhaTemp, valor);
    }
    
    while(!verificaPilhaVazia(pilhaTemp))
    {
        int valor = desempilha(pilhaTemp);
        empilha(pilhaOriginal, valor);
    }
    
    liberaPilha(pilhaAuxiliar);
    liberaPilha(pilhaTemp);
    
    printf("Remocao de duplicados concluida!\n");
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

