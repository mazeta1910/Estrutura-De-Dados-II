#ifndef ITEMFILAENC_H_INCLUDED
#define ITEMFILAENC_H_INCLUDED

typedef struct item Item;
typedef struct celula Celula;
typedef struct fila Fila;

Fila *criaFilaVazia();
void enfileira(Fila *f, int chave);
void imprimeFila(Fila *f);
void desenfileira(Fila *f);
int verificaFilaVazia(Fila *f);
void liberaFila(Fila *f);

#endif // ITEMFILAENC_H_INCLUDED
