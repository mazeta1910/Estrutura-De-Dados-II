#include "Data.h"

typedef struct curso Curso;
typedef struct celula Celula;
typedef struct pilha Pilha;

Pilha* criaPilha();
void liberaPilha(Pilha* pi);
int verificaPilhaVazia(Pilha* pi);
void empilhaCurso(Pilha* pi, int id, char* nome, Data* dataConclusao, char* plataforma);
void desempilhaCurso(Pilha* pi);
void imprimePilha(Pilha* pi);

