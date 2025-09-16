#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"

struct arvore
{
    int chave;
    char regiao[100];
    char especie[100];
    int quantidade;
};

struct celula
{
    Arvore arvore;
    Celula *ant;
    Celula *prox;
};

struct deque
{
    Celula *ini;
    Celula *fim;
    int proximaChave;
};

Deque* criaDeque()
{
    Deque* dq = (Deque*) malloc(sizeof(Deque));
    if(dq != NULL)
    {
        dq->ini = NULL;
        dq->fim = NULL;
        dq->proximaChave = 1;
    }
    return dq;
}

int verificaDequeVazio(Deque* dq)
{
    return (dq->ini == NULL);
}

// Busca se já existe uma espécie na mesma região
Arvore* buscaEspecieRegiao(Deque* dq, char* regiao, char* especie)
{
    if(verificaDequeVazio(dq))
        return NULL;
    
    Celula *aux = dq->ini;
    while(aux != NULL)
    {
        if(strcmp(aux->arvore.regiao, regiao) == 0 && 
           strcmp(aux->arvore.especie, especie) == 0)
        {
            return &(aux->arvore);
        }
        aux = aux->prox;
    }
    return NULL;
}

void insereArvore(Deque* dq, char* regiao, char* especie, int quantidade)
{
    // Verifica se já existe a espécie na região
    Arvore* existente = buscaEspecieRegiao(dq, regiao, especie);
    
    if(existente != NULL)
    {
        // Atualiza quantidade existente
        existente->quantidade += quantidade;
        printf("* Identificado registro existente, atualizada a quantidade.\n");
        return;
    }
    
    // Cria nova árvore
    Arvore nova;
    nova.chave = dq->proximaChave++;
    strcpy(nova.regiao, regiao);
    strcpy(nova.especie, especie);
    nova.quantidade = quantidade;
    
    // Cria nova célula e insere no fim (como um deque normal)
    Celula *novaCelula = malloc(sizeof(Celula));
    novaCelula->arvore = nova;
    novaCelula->ant = dq->fim;
    novaCelula->prox = NULL;
    
    if(verificaDequeVazio(dq))
    {
        dq->ini = novaCelula;
    }
    else
    {
        dq->fim->prox = novaCelula;
    }
    
    dq->fim = novaCelula;
}

void removeUltimo(Deque* dq)
{
    if(verificaDequeVazio(dq))
    {
        printf("Nenhum registro para remover!\n");
        return;
    }
    
    Celula *remover = dq->fim;
    Arvore arvoreRemovida = remover->arvore;
    
    // Verifica se existe outra entrada da mesma espécie na mesma região
    Celula *aux = dq->ini;
    int encontrouOutra = 0;
    while(aux != remover && aux != NULL)
    {
        if(strcmp(aux->arvore.regiao, arvoreRemovida.regiao) == 0 && 
           strcmp(aux->arvore.especie, arvoreRemovida.especie) == 0)
        {
            // Subtrai a quantidade que estava sendo removida
            aux->arvore.quantidade -= arvoreRemovida.quantidade;
            if(aux->arvore.quantidade < 0)
                aux->arvore.quantidade = 0;
            encontrouOutra = 1;
            break;
        }
        aux = aux->prox;
    }
    
    // Remove a célula do fim
    dq->fim = remover->ant;
    
    if(dq->fim == NULL) // Se ficou vazio
    {
        dq->ini = NULL;
    }
    else
    {
        dq->fim->prox = NULL;
    }
    
    printf("Ultimo registro removido: %s - %s (Quantidade: %d)\n", 
           arvoreRemovida.regiao, arvoreRemovida.especie, arvoreRemovida.quantidade);
    
    if(encontrouOutra)
    {
        printf("Quantidade atualizada em registro anterior da mesma especie.\n");
    }
    
    free(remover);
}

void imprimeInventario(Deque* dq)
{
    if(verificaDequeVazio(dq))
    {
        printf("Inventario vazio!\n");
        return;
    }
    
    printf("\n===Especies de arvores identificadas por regiao inventariada ===\n");
    
    Celula *aux = dq->ini;
    while(aux != NULL)
    {
        printf("* %s\n", aux->arvore.regiao);
        printf("Chave: %d - Especie %s - Quantidade: %d\n", 
               aux->arvore.chave, aux->arvore.especie, aux->arvore.quantidade);
        aux = aux->prox;
    }
}

void calculaPorcentagens(Deque* dq)
{
    if(verificaDequeVazio(dq))
    {
        printf("Inventario vazio!\n");
        return;
    }
    
    printf("\n===Porcentagem de arvores por regiao===\n");
    
    // Para cada registro, calcula o total da região e a porcentagem
    Celula *aux = dq->ini;
    while(aux != NULL)
    {
        int totalRegiao = 0;
        
        // Calcula total de árvores na região
        Celula *auxTotal = dq->ini;
        while(auxTotal != NULL)
        {
            if(strcmp(auxTotal->arvore.regiao, aux->arvore.regiao) == 0)
            {
                totalRegiao += auxTotal->arvore.quantidade;
            }
            auxTotal = auxTotal->prox;
        }
        
        // Calcula porcentagem
        float porcentagem = (float)aux->arvore.quantidade / totalRegiao * 100;
        
        printf("%s\n", aux->arvore.regiao);
        printf("* %d arvores da especie %s, equivalente a %.2f %% de arvores da regiao (Total: %d).\n",
               aux->arvore.quantidade, aux->arvore.especie, porcentagem, totalRegiao);
        
        aux = aux->prox;
    }
}

void especieMaisFrequente(Deque* dq)
{
    if(verificaDequeVazio(dq))
    {
        printf("Inventario vazio!\n");
        return;
    }
    
    // Arrays para armazenar espécies e suas quantidades totais
    char especies[100][100];
    int quantidades[100];
    int numEspecies = 0;
    
    // Soma quantidades por espécie (independente da região)
    Celula *aux = dq->ini;
    while(aux != NULL)
    {
        // Verifica se a espécie já foi contabilizada
        int encontrada = 0;
        for(int i = 0; i < numEspecies; i++)
        {
            if(strcmp(especies[i], aux->arvore.especie) == 0)
            {
                quantidades[i] += aux->arvore.quantidade;
                encontrada = 1;
                break;
            }
        }
        
        // Se não encontrou, adiciona nova espécie
        if(!encontrada && numEspecies < 100)
        {
            strcpy(especies[numEspecies], aux->arvore.especie);
            quantidades[numEspecies] = aux->arvore.quantidade;
            numEspecies++;
        }
        
        aux = aux->prox;
    }
    
    // Encontra a espécie mais frequente
    int maiorQuantidade = 0;
    char especieMaior[100];
    
    for(int i = 0; i < numEspecies; i++)
    {
        if(quantidades[i] > maiorQuantidade)
        {
            maiorQuantidade = quantidades[i];
            strcpy(especieMaior, especies[i]);
        }
    }
    
    printf("\n===Especie mais frequente===\n");
    printf("Especie: %s\n", especieMaior);
    printf("Quantidade total: %d arvores\n", maiorQuantidade);
    
    // Mostra todas as espécies para comparação
    printf("\n===Todas as especies===\n");
    for(int i = 0; i < numEspecies; i++)
    {
        printf("%s: %d arvores\n", especies[i], quantidades[i]);
    }
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

