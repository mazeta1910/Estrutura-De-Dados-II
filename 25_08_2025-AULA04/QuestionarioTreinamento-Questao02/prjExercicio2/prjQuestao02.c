#include <stdio.h>
#include <stdlib.h>
#include "prjQuestao02.h"

//Struct nó - unidade da lista
struct no {
    int valor;
    struct no* prox;
};

//Struct Lista
struct lista {
    struct no* inicio;
};

Lista* criarLista(void) {
    Lista* novaLista = (Lista*) malloc(sizeof(Lista));
    if (novaLista != NULL) {
        novaLista->inicio = NULL;
    }
    return novaLista;
}

//Inserindo elemento no final da lista
void listaInserirFim(Lista *l, int valor){
    if (l==NULL) return; // se falhar sai da funcao

    struct no* novoNo = (struct no*) malloc(sizeof(struct no)); // alocação, criar novo nó na memória
    if(novoNo == NULL) return;

    // INICIALIZAÇÃO
    novoNo -> valor = valor; // armazena o valor
    novoNo -> prox = NULL; // define como último elemento

    // INSERÇÃO
    if (l-> inicio == NULL){
        //lista vazia
        l->inicio = novoNo; //Lista vazia - novo nó se torna o primeiro
    } else {
        struct no* atual = l-> inicio; //caso n esteja vazia, percorre até o final
        while (atual->prox != NULL){
            atual = atual->prox; // avança até o último nó
        }
        atual->prox = novoNo; // ultimo nó aponta para o novo
    }
}

void listaConcatenar(Lista* l1, Lista* l2){
    if (l1 == NULL || l2 == NULL) return; // Verifica se a lista é válida
    if (l1 -> inicio == NULL){ // caso l1 está vazia, l1 recebe toda l2
        l1->inicio = l2->inicio;
    } else {
        struct no* atual = l1->inicio;
        while (atual->prox != NULL){
            atual = atual -> prox;
        }
        // Conecta o ultimo nó de l1 com o primeiro de l2
        atual->prox = l2->inicio;
    }

    //Esvazia o l2 para evitar acesso aos mesmos nós
    l2->inicio = NULL;
}

void listaImprimir(Lista* l) {
    if (l == NULL) return;  // Verifica se a lista é válida

    struct no* atual = l->inicio;  // Começa pelo primeiro nó

    printf("Lista: ");
    while (atual != NULL) {  // Percorre até o final
        printf("%d ", atual->valor);  // Imprime o valor
        atual = atual->prox;          // Avança para o próximo
    }
    printf("\n");
}

void listaLiberar(Lista* l) {
    if (l == NULL) return;  // Verifica se a lista é válida

    struct no* atual = l->inicio;
    struct no* proximo;

    // Libera cada nó individualmente
    while (atual != NULL) {
        proximo = atual->prox;  // Salva referência para o próximo
        free(atual);            // Libera o nó atual
        atual = proximo;        // Avança para o próximo
    }

    free(l);  // Libera a estrutura da lista
}

/*Struct no: Representa cada elemento (nó) da lista. Contém o dado (valor) e um ponteiro para o próximo nó (prox).
Struct lista: É uma struct que contém um ponteiro para o primeiro nó. Isso facilita o controle da lista como um todo.*/

