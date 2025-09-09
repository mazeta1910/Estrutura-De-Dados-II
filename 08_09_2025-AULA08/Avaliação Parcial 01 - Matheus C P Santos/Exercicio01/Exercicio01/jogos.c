#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogos.h"
#define ANO_ATUAL 2025
#define ANO_MIN 1970

struct jogo
{
    char codigo[6];
    char nome[100];
    char plataforma[20];
    int ano;
    char estado[20];
};

struct celula
{
    Jogo jogo;
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

// Gera o próximo codigo disponviel
char* geraProximoCodigo(Lista* li, char* plataforma)
{
    char* prefixo;
    int contador = 1;

    // Prefixo do código para platafomras
    if(strcmp(plataforma, "PC") == 0) {
        prefixo = "PC";
    } else if(strcmp(plataforma, "PS5") == 0) {
        prefixo = "PS";
    } else if(strcmp(plataforma, "Xbox") == 0) {
        prefixo = "XB";
    } else if(strcmp(plataforma, "Switch") == 0) {
        prefixo = "SW";
    } else if(strcmp(plataforma, "Mobile") == 0) {
        prefixo = "MB";
    } else {
        prefixo = "XX"; // Plataforma desconhecida
    }

    // Conta qts jogos ja tem para a plataforma
    Celula *aux = li->ini;
    while(aux != NULL)
    {
        if(strcmp(aux->jogo.plataforma, plataforma) == 0)
        {
            contador++;
        }
        aux = aux->prox;
    }

    // Gera o codigo formatado
    char* codigo = malloc(6 * sizeof(char));
    sprintf(codigo, "%s%02d", prefixo, contador);

    return codigo;
}

void insereLista(Lista* li, char* nome, char* plataforma, int ano, char* estado)
{
    // Gerar código automaticamente
    char* codigoGerado = geraProximoCodigo(li, plataforma);

    // Validação do ano
    if (ano < ANO_MIN || ano > ANO_ATUAL + 2){
        printf("Erro: Ano deve estar entre %d e %d!\n", ANO_MIN, ANO_ATUAL+2);
        free(codigoGerado);
        return;
    }

    // Cria novo jogo
    Jogo novo;
    strcpy(novo.codigo, codigoGerado);
    strcpy(novo.nome, nome);
    strcpy(novo.plataforma, plataforma);
    novo.ano = ano;
    strcpy(novo.estado, estado);

    // Cria nova célula
    Celula *nova = malloc(sizeof(Celula));
    nova->jogo = novo;
    nova->prox = li->ini;
    li->ini = nova;

    // Aviso de sucesso
    printf("Jogo '%s' adicionado com sucesso! Codigo gerado: %s\n", nome, codigoGerado);

    free(codigoGerado);
}

void removeLista(Lista* li, char* codigo)
{
    if(verificaListaVazia(li))
    {
        printf("Erro: Lista vazia!\n");
        return;
    }

    Celula *atual = li->ini;
    Celula *anterior = NULL;

    while(atual != NULL && strcmp(atual->jogo.codigo, codigo) != 0)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL)
    {
        printf("Erro: Jogo com codigo %s nao encontrado!\n", codigo);
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
    printf("Jogo com codigo %s removido com sucesso!\n", codigo);
}

int buscaLista(Lista* li, char* codigo)
{
    Celula *aux = li->ini;
    while(aux != NULL)
    {
        if(strcmp(aux->jogo.codigo, codigo) == 0)
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
        printf("Lista vazia!\n");
        return;
    }

    Celula *aux = li->ini;
    printf("\n=== LISTA DE JOGOS ===\n");
    while(aux != NULL)
    {
        printf("Codigo: %s\n", aux->jogo.codigo);
        printf("Nome: %s\n", aux->jogo.nome);
        printf("Plataforma: %s\n", aux->jogo.plataforma);
        printf("Ano: %d\n", aux->jogo.ano);
        printf("Estado: %s\n", aux->jogo.estado);
        printf("----------------------\n");
        aux = aux->prox;
    }
}

Lista* copiaFinalizados(Lista* li)
{
    Lista* novaLista = criaLista();

    if(verificaListaVazia(li))
    {
        return novaLista;
    }

    Celula *aux = li->ini;
    while(aux != NULL)
    {
        if(strcmp(aux->jogo.estado, "Finalizado") == 0)
        {
            insereLista(novaLista, aux->jogo.nome, aux->jogo.plataforma,
                       aux->jogo.ano, aux->jogo.estado);
        }
        aux = aux->prox;
    }

    return novaLista;
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

