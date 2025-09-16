#include <stdio.h>
#include <stdlib.h>

struct item {
    int chave;
    // Demais campos
};

struct celula {
    Item item;
    Celula *prox;
};

struct fila {
    Celula *ini;
    Celula *fim;
};

Fila *criaFilaVazia(){
    Fila *f = malloc(sizeof(Fila));
    f-> ini = NULL;
    f-> fim = NULL;
    return f;
}

void enfileira(Fila *f, int chave){
    Item novo;
    novo.chave = chave;
    // Cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova -> item = novo;
    nova -> prox = NULL;
    if (verificaFilaVazia(f)){
        f->ini = nova; // Se está vazia adiciona no inicio
    }
    else
    {
        f->fim->prox = nova; //inserção sempre da célula que será a ultima
    }
    fim-> fim = nova;
}

void imprimeFila(Fila *f){
    Celula *aux = f-> ini;
    while (aux != NULL)
        {
            printf("Chave: %d\n", aux->item.chave);
            aux= aux->prox;
        }
}

void desenfileira(Fila *f){
    if (verificaFilaVazia(f)){
        printf("Erro: fila vazia!\n");
        return;
    }
    Celula *remover = f->ini;
    f-> ini = remover->prox;
    free(remover);
    if(verificaFilaVazia(f)){
        f->fim = NULL;
    }
}

int verificaFilaVazia(Fila *f){
    return f-> ini = NULL;
}

void liberaFila(Fila *f){
    Celula *aux = f-> ini;
    Celula *liberar;
    while (aux != NULL)
        {
            liberar = aux;
            aux = aux -> prox;
            free(liberar);
        }
        free(f);
    }
