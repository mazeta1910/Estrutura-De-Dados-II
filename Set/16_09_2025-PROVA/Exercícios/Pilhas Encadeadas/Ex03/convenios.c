#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convenios.h"

struct matheus
{
    char empresa[100];
    char area[50];
    float desconto;
};

struct celula
{
    Matheus convenio;
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

void empilhaConvenio(Pilha* pi, char* empresa, char* area, float desconto)
{
    // Verifica se já existe um convênio com a mesma empresa
    if(buscaConvenio(pi, empresa))
    {
        printf("Erro: Convenio com empresa '%s' ja existe!\n", empresa);
        return;
    }
    
    // Validação do desconto
    if(desconto < 0 || desconto > 100)
    {
        printf("Erro: Desconto deve estar entre 0%% e 100%%!\n");
        return;
    }
    
    // Cria novo convênio
    Matheus novo;
    strcpy(novo.empresa, empresa);
    strcpy(novo.area, area);
    novo.desconto = desconto;
    
    // Cria nova célula
    Celula *nova = malloc(sizeof(Celula));
    nova->convenio = novo;
    nova->prox = pi->topo;
    pi->topo = nova;
    
    printf("Convenio com '%s' cadastrado com sucesso!\n", empresa);
}

void desempilhaConvenio(Pilha* pi)
{
    if(verificaPilhaVazia(pi))
    {
        printf("Erro: Pilha vazia!\n");
        return;
    }
    
    Celula *remover = pi->topo;
    pi->topo = remover->prox;
    
    printf("Convenio com '%s' removido com sucesso!\n", remover->convenio.empresa);
    free(remover);
}

int buscaConvenio(Pilha* pi, char* empresa)
{
    if(verificaPilhaVazia(pi))
    {
        return 0; // Não encontrado
    }
    
    // Pilha temporária para preservar a pilha original
    Pilha* temp = criaPilha();
    int encontrado = 0;
    
    // Desempilha todos os elementos procurando a empresa
    while(!verificaPilhaVazia(pi))
    {
        Celula *atual = pi->topo;
        Matheus convenio = atual->convenio;
        
        // Move para pilha temporária
        empilhaConvenio(temp, convenio.empresa, convenio.area, convenio.desconto);
        desempilhaConvenio(pi);
        
        if(strcmp(convenio.empresa, empresa) == 0)
        {
            encontrado = 1;
        }
    }
    
    // Restaura a pilha original
    while(!verificaPilhaVazia(temp))
    {
        Celula *atual = temp->topo;
        Matheus convenio = atual->convenio;
        
        // Move de volta para pilha original
        Celula *nova = malloc(sizeof(Celula));
        nova->convenio = convenio;
        nova->prox = pi->topo;
        pi->topo = nova;
        
        // Remove da pilha temporária
        temp->topo = atual->prox;
        free(atual);
    }
    
    liberaPilha(temp);
    return encontrado;
}

void imprimePilha(Pilha* pi)
{
    if(verificaPilhaVazia(pi))
    {
        printf("Nenhum convenio cadastrado!\n");
        return;
    }
    
    Celula *aux = pi->topo;
    printf("\n=== CONVENIOS CADASTRADOS ===\n");
    int contador = 1;
    
    while(aux != NULL)
    {
        printf("Convenio %d:\n", contador);
        printf("Empresa: %s\n", aux->convenio.empresa);
        printf("Area de Atuacao: %s\n", aux->convenio.area);
        printf("Desconto: %.1f%%\n", aux->convenio.desconto);
        printf("---------------------------\n");
        aux = aux->prox;
        contador++;
    }
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

