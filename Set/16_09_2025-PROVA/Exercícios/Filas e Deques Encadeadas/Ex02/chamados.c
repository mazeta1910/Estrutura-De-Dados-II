#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "chamados.h"

struct matheus
{
    int id;
    char nomeUsuario[100];
    char problema[200];
    char prioridade[20];
    char dataHora[30];
};

struct celula
{
    Matheus chamado;
    Celula *prox;
};

struct fila
{
    Celula *ini;
    Celula *fim;
    int proximoId;
};

Fila* criaFilaVazia()
{
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL)
    {
        fi->ini = NULL;
        fi->fim = NULL;
        fi->proximoId = 1;
    }
    return fi;
}

int verificaFilaVazia(Fila* fi)
{
    return (fi->ini == NULL);
}

void enfileiraChamado(Fila* fi, char* nomeUsuario, char* problema, char* prioridade)
{
    // Cria novo chamado
    Matheus novo;
    novo.id = fi->proximoId++;
    strcpy(novo.nomeUsuario, nomeUsuario);
    strcpy(novo.problema, problema);
    strcpy(novo.prioridade, prioridade);
    
    // Gera data/hora atual
    time_t tempo;
    struct tm *dataAtual;
    tempo = time(NULL);
    dataAtual = localtime(&tempo);
    sprintf(novo.dataHora, "%02d/%02d/%04d %02d:%02d", 
            dataAtual->tm_mday, dataAtual->tm_mon + 1, dataAtual->tm_year + 1900,
            dataAtual->tm_hour, dataAtual->tm_min);
    
    // Cria nova célula
    Celula *nova = malloc(sizeof(Celula));
    nova->chamado = novo;
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
    
    printf("Chamado #%d de '%s' adicionado a fila de suporte!\n", novo.id, nomeUsuario);
}

void desenfileiraChamado(Fila* fi)
{
    if(verificaFilaVazia(fi))
    {
        printf("Erro: Nenhum chamado na fila!\n");
        return;
    }
    
    Celula *remover = fi->ini;
    fi->ini = remover->prox;
    
    printf("Chamado #%d de '%s' foi atendido e removido da fila!\n", 
           remover->chamado.id, remover->chamado.nomeUsuario);
    
    free(remover);
    
    if(verificaFilaVazia(fi)) // Se ficou vazia...
    {
        fi->fim = NULL; // Não há mais célula no fim
    }
}

int buscaChamado(Fila* fi, char* nomeUsuario)
{
    if(verificaFilaVazia(fi))
    {
        return 0; // Não encontrado
    }
    
    Celula *aux = fi->ini;
    while(aux != NULL)
    {
        if(strcmp(aux->chamado.nomeUsuario, nomeUsuario) == 0)
        {
            return 1; // Encontrado
        }
        aux = aux->prox;
    }
    return 0; // Não encontrado
}

void imprimeFila(Fila* fi)
{
    if(verificaFilaVazia(fi))
    {
        printf("Nenhum chamado na fila de suporte!\n");
        return;
    }
    
    Celula *aux = fi->ini;
    printf("\n=== FILA DE CHAMADOS DE SUPORTE ===\n");
    printf("(Primeiro da fila sera o proximo a ser atendido)\n\n");
    int posicao = 1;
    
    while(aux != NULL)
    {
        printf("Posicao %d na fila:\n", posicao);
        printf("ID do Chamado: #%d\n", aux->chamado.id);
        printf("Usuario: %s\n", aux->chamado.nomeUsuario);
        printf("Problema: %s\n", aux->chamado.problema);
        printf("Prioridade: %s\n", aux->chamado.prioridade);
        printf("Data/Hora: %s\n", aux->chamado.dataHora);
        printf("--------------------------------\n");
        aux = aux->prox;
        posicao++;
    }
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

