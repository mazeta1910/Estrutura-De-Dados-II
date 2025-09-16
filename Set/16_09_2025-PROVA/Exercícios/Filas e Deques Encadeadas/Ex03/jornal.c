#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jornal.h"

struct noticia
{
    int id;
    char titulo[150];
    char conteudo[500];
    char classificacao[30];
    char autor[100];
    char dataHora[30];
};

struct celula
{
    Noticia noticia;
    Celula *ant;
    Celula *prox;
};

struct deque
{
    Celula *ini;
    Celula *fim;
    int proximoId;
};

Deque* criaDeque()
{
    Deque* dq = (Deque*) malloc(sizeof(Deque));
    if(dq != NULL)
    {
        dq->ini = NULL;
        dq->fim = NULL;
        dq->proximoId = 1;
    }
    return dq;
}

int verificaDequeVazio(Deque* dq)
{
    return (dq->ini == NULL);
}

// Função auxiliar para gerar data/hora atual
void geraDataHora(char* dataHora)
{
    time_t tempo;
    struct tm *dataAtual;
    tempo = time(NULL);
    dataAtual = localtime(&tempo);
    sprintf(dataHora, "%02d/%02d/%04d %02d:%02d", 
            dataAtual->tm_mday, dataAtual->tm_mon + 1, dataAtual->tm_year + 1900,
            dataAtual->tm_hour, dataAtual->tm_min);
}

// Inserção no início (notícias prioritárias)
void insereInicio(Deque* dq, char* titulo, char* conteudo, char* classificacao, char* autor)
{
    // Cria nova notícia
    Noticia nova;
    nova.id = dq->proximoId++;
    strcpy(nova.titulo, titulo);
    strcpy(nova.conteudo, conteudo);
    strcpy(nova.classificacao, classificacao);
    strcpy(nova.autor, autor);
    geraDataHora(nova.dataHora);
    
    // Cria nova célula
    Celula *novaCelula = malloc(sizeof(Celula));
    novaCelula->noticia = nova;
    novaCelula->ant = NULL;
    novaCelula->prox = dq->ini;
    
    if(verificaDequeVazio(dq))
    {
        dq->fim = novaCelula; // Se estava vazio, é também o fim
    }
    else
    {
        dq->ini->ant = novaCelula; // Liga o antigo primeiro à nova célula
    }
    
    dq->ini = novaCelula; // Nova célula vira o início
    
    printf("Noticia PRIORITARIA #%d '%s' adicionada no inicio!\n", nova.id, titulo);
}

// Inserção no fim (ordem normal de recebimento)
void insereFim(Deque* dq, char* titulo, char* conteudo, char* classificacao, char* autor)
{
    // Cria nova notícia
    Noticia nova;
    nova.id = dq->proximoId++;
    strcpy(nova.titulo, titulo);
    strcpy(nova.conteudo, conteudo);
    strcpy(nova.classificacao, classificacao);
    strcpy(nova.autor, autor);
    geraDataHora(nova.dataHora);
    
    // Cria nova célula
    Celula *novaCelula = malloc(sizeof(Celula));
    novaCelula->noticia = nova;
    novaCelula->ant = dq->fim;
    novaCelula->prox = NULL;
    
    if(verificaDequeVazio(dq))
    {
        dq->ini = novaCelula; // Se estava vazio, é também o início
    }
    else
    {
        dq->fim->prox = novaCelula; // Liga o antigo último à nova célula
    }
    
    dq->fim = novaCelula; // Nova célula vira o fim
    
    printf("Noticia #%d '%s' adicionada no final!\n", nova.id, titulo);
}

// Remoção do início
void removeInicio(Deque* dq)
{
    if(verificaDequeVazio(dq))
    {
        printf("Erro: Nenhuma noticia no jornal!\n");
        return;
    }
    
    Celula *remover = dq->ini;
    dq->ini = remover->prox;
    
    if(dq->ini == NULL) // Se ficou vazio
    {
        dq->fim = NULL;
    }
    else
    {
        dq->ini->ant = NULL;
    }
    
    printf("Noticia #%d '%s' removida do inicio!\n", 
           remover->noticia.id, remover->noticia.titulo);
    free(remover);
}

// Remoção do fim
void removeFim(Deque* dq)
{
    if(verificaDequeVazio(dq))
    {
        printf("Erro: Nenhuma noticia no jornal!\n");
        return;
    }
    
    Celula *remover = dq->fim;
    dq->fim = remover->ant;
    
    if(dq->fim == NULL) // Se ficou vazio
    {
        dq->ini = NULL;
    }
    else
    {
        dq->fim->prox = NULL;
    }
    
    printf("Noticia #%d '%s' removida do final!\n", 
           remover->noticia.id, remover->noticia.titulo);
    free(remover);
}

void imprimeDeque(Deque* dq)
{
    if(verificaDequeVazio(dq))
    {
        printf("Jornal vazio - nenhuma noticia cadastrada!\n");
        return;
    }
    
    Celula *aux = dq->ini;
    printf("\n=== JORNAL DIGITAL DA EMPRESA ===\n");
    printf("(Ordem de publicacao: do mais recente ao mais antigo)\n\n");
    
    while(aux != NULL)
    {
        printf("ID: #%d\n", aux->noticia.id);
        printf("TITULO: %s\n", aux->noticia.titulo);
        printf("CLASSIFICACAO: %s\n", aux->noticia.classificacao);
        printf("AUTOR: %s\n", aux->noticia.autor);
        printf("DATA/HORA: %s\n", aux->noticia.dataHora);
        printf("CONTEUDO: %s\n", aux->noticia.conteudo);
        printf("=====================================\n");
        aux = aux->prox;
    }
}

// Função para calcular estatísticas por classificação
void estatisticasClassificacao(Deque* dq)
{
    if(verificaDequeVazio(dq))
    {
        printf("Nenhuma noticia para calcular estatisticas!\n");
        return;
    }
    
    // Arrays para armazenar classificações e contadores
    char classificacoes[50][30];
    int contadores[50];
    int numClassificacoes = 0;
    int totalNoticias = 0;
    
    // Percorre o deque contando notícias por classificação
    Celula *aux = dq->ini;
    while(aux != NULL)
    {
        totalNoticias++;
        
        // Verifica se a classificação já existe
        int encontrada = 0;
        for(int i = 0; i < numClassificacoes; i++)
        {
            if(strcmp(classificacoes[i], aux->noticia.classificacao) == 0)
            {
                contadores[i]++;
                encontrada = 1;
                break;
            }
        }
        
        // Se não encontrou, adiciona nova classificação
        if(!encontrada && numClassificacoes < 50)
        {
            strcpy(classificacoes[numClassificacoes], aux->noticia.classificacao);
            contadores[numClassificacoes] = 1;
            numClassificacoes++;
        }
        
        aux = aux->prox;
    }
    
    // Encontra a classificação com maior número de notícias
    int maiorContador = 0;
    char classificacaoMaior[30];
    
    for(int i = 0; i < numClassificacoes; i++)
    {
        if(contadores[i] > maiorContador)
        {
            maiorContador = contadores[i];
            strcpy(classificacaoMaior, classificacoes[i]);
        }
    }
    
    // Exibe estatísticas
    printf("\n=== ESTATISTICAS POR CLASSIFICACAO ===\n");
    printf("Total de noticias: %d\n\n", totalNoticias);
    
    for(int i = 0; i < numClassificacoes; i++)
    {
        float percentual = (float)contadores[i] / totalNoticias * 100;
        printf("%s: %d noticias (%.1f%%)\n", 
               classificacoes[i], contadores[i], percentual);
    }
    
    float percentualMaior = (float)maiorContador / totalNoticias * 100;
    printf("\nClassificacao com MAIOR numero de noticias:\n");
    printf("'%s' com %d noticias (%.1f%% do total)\n", 
           classificacaoMaior, maiorContador, percentualMaior);
}

void liberaDeque(Deque* dq)
{
    Celula *aux = dq->ini;
    Celula *liberar;
    while(aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(dq);
}

