#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct item {
    int chave;
    char dados[100];
} Item;

typedef struct celula {
    Item item;
    struct celula *ant;
    struct celula *prox;
} Celula;

typedef struct lista {
    Celula *ini;
    Celula *fim;
} Lista;

Lista* criaLista() {
    Lista* li = malloc(sizeof(Lista));
    if(li != NULL) {
        li->ini = NULL;
        li->fim = NULL;
    }
    return li;
}

int verificaListaVazia(Lista* li) {
    return (li->ini == NULL);
}

void insereLista(Lista* li, int chave, char* dados) {
    Item novo;
    novo.chave = chave;
    strcpy(novo.dados, dados);

    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->ant = li->fim;
    nova->prox = NULL;

    if(verificaListaVazia(li)) {
        li->ini = nova;
    } else {
        li->fim->prox = nova;
    }
    li->fim = nova;
}

// FUNÇÃO PRINCIPAL: Inverte sem lista auxiliar
void inverteLista(Lista* li) {
    if(verificaListaVazia(li)) {
        printf("Lista vazia!\n");
        return;
    }

    if(li->ini->prox == NULL) {
        printf("1 elemento, ja invertida.\n");
        return;
    }

    Celula *atual = li->ini;
    Celula *temp = NULL;

    // Troca ponteiros de cada célula
    while(atual != NULL) {
        temp = atual->prox;
        atual->prox = atual->ant;
        atual->ant = temp;
        atual = temp;
    }

    // Troca ini e fim
    temp = li->ini;
    li->ini = li->fim;
    li->fim = temp;

    printf("Lista invertida!\n");
}

void imprimeLista(Lista* li) {
    if(verificaListaVazia(li)) {
        printf("Lista vazia!\n");
        return;
    }

    Celula *aux = li->ini;
    printf("Lista: ");
    while(aux != NULL) {
        printf("%d ", aux->item.chave);
        aux = aux->prox;
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Lista* lista = criaLista();

    // Exemplo: 15, 20, 30, 40, 80
    insereLista(lista, 15, "Quinze");
    insereLista(lista, 20, "Vinte");
    insereLista(lista, 30, "Trinta");
    insereLista(lista, 40, "Quarenta");
    insereLista(lista, 80, "Oitenta");

    printf("Original: ");
    imprimeLista(lista);

    inverteLista(lista);

    printf("Invertida: ");
    imprimeLista(lista);

    return 0;
}
