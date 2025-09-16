#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

struct matheus
{
    char nome[100];
    char telefone[20];
    char email[100];
};

struct celula
{
    Matheus contato;
    Celula *prox;
};

struct lista
{
    Celula *ini;
};

Lista* criaLista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
    {
        li->ini = NULL;
    }
    return li;
}

int verificaListaVazia(Lista* li)
{
    return (li->ini == NULL);
}

void insereLista(Lista* li, char* nome, char* telefone, char* email)
{
    // Verifica se já existe um contato com o mesmo nome
    if(buscaLista(li, nome))
    {
        printf("Erro: Contato com nome '%s' ja existe!\n", nome);
        return;
    }
    
    // Cria novo contato
    Matheus novo;
    strcpy(novo.nome, nome);
    strcpy(novo.telefone, telefone);
    strcpy(novo.email, email);
    
    // Cria nova célula
    Celula *nova = malloc(sizeof(Celula));
    nova->contato = novo;
    nova->prox = li->ini;
    li->ini = nova;
    
    printf("Contato '%s' adicionado com sucesso!\n", nome);
}

void removeLista(Lista* li, char* nome)
{
    if(verificaListaVazia(li))
    {
        printf("Erro: Lista vazia!\n");
        return;
    }
    
    Celula *atual = li->ini;
    Celula *anterior = NULL;
    
    while(atual != NULL && strcmp(atual->contato.nome, nome) != 0)
    {
        anterior = atual;
        atual = atual->prox;
    }
    
    if(atual == NULL)
    {
        printf("Erro: Contato '%s' nao encontrado!\n", nome);
        return;
    }
    
    if(anterior == NULL) // Remove o primeiro
    {
        li->ini = atual->prox;
    }
    else
    {
        anterior->prox = atual->prox;
    }
    
    free(atual);
    printf("Contato '%s' removido com sucesso!\n", nome);
}

int buscaLista(Lista* li, char* nome)
{
    Celula *aux = li->ini;
    while(aux != NULL)
    {
        if(strcmp(aux->contato.nome, nome) == 0)
        {
            return 1; // Encontrado
        }
        aux = aux->prox;
    }
    return 0; // Não encontrado
}

void imprimeLista(Lista* li)
{
    if(verificaListaVazia(li))
    {
        printf("Agenda vazia!\n");
        return;
    }
    
    Celula *aux = li->ini;
    printf("\n=== AGENDA TELEFONICA ===\n");
    while(aux != NULL)
    {
        printf("Nome: %s\n", aux->contato.nome);
        printf("Telefone: %s\n", aux->contato.telefone);
        printf("E-mail: %s\n", aux->contato.email);
        printf("------------------------\n");
        aux = aux->prox;
    }
}

void liberaLista(Lista* li)
{
    Celula *aux = li->ini;
    Celula *liberar;
    while(aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(li);
}

