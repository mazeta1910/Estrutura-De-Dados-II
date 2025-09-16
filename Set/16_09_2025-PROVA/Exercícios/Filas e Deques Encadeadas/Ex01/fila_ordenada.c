#include <stdio.h>
#include <stdlib.h>
#include "fila_ordenada.h"

struct item
{
    int valor;
};

struct celula
{
    Item item;
    Celula *prox;
};

struct fila
{
    Celula *ini;
    Celula *fim;
};

Fila* criaFilaVazia()
{
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL)
    {
        fi->ini = NULL;
        fi->fim = NULL;
    }
    return fi;
}

int verificaFilaVazia(Fila* fi)
{
    return (fi->ini == NULL);
}

void enfileira(Fila* fi, int valor)
{
    // Cria novo item
    Item novo;
    novo.valor = valor;
    
    // Cria nova célula
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = NULL;
    
    if(verificaFilaVazia(fi))
    {
        fi->ini = nova; // Se está vazia adiciona no início
    }
    else
    {
        fi->fim->prox = nova;
    }
    fi->fim = nova; // Enfileira sempre a célula que será a última
}

void desenfileira(Fila* fi)
{
    if(verificaFilaVazia(fi))
    {
        printf("Erro: Fila vazia!\n");
        return;
    }
    
    Celula *remover = fi->ini;
    fi->ini = remover->prox;
    free(remover);
    
    if(verificaFilaVazia(fi)) // Se ficou vazia...
    {
        fi->fim = NULL; // Não há mais célula no fim
    }
}

// FUNÇÃO PRINCIPAL: Verifica se a fila está ordenada em ordem crescente
int verificaFilaOrdenada(Fila* fi)
{
    // Fila vazia ou com um elemento é considerada ordenada
    if(verificaFilaVazia(fi) || fi->ini->prox == NULL)
    {
        return 1; // Ordenada
    }
    
    Celula *atual = fi->ini;
    
    // Percorre a fila comparando elementos adjacentes
    while(atual->prox != NULL)
    {
        // Se elemento atual é maior que o próximo, não está ordenada
        if(atual->item.valor > atual->prox->item.valor)
        {
            return 0; // Não ordenada
        }
        atual = atual->prox;
    }
    
    return 1; // Ordenada
}

void imprimeFila(Fila* fi)
{
    if(verificaFilaVazia(fi))
    {
        printf("Fila vazia!\n");
        return;
    }
    
    Celula *aux = fi->ini;
    printf("Fila (inicio -> fim): ");
    while(aux != NULL)
    {
        printf("%d ", aux->item.valor);
        aux = aux->prox;
    }
    printf("\n");
}

void liberaFila(Fila* fi)
{
    Celula *aux = fi->ini;
    Celula *liberar;
    while(aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(fi);
}

