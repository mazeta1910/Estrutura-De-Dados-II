typedef struct item Item;
typedef struct celula Celula;
typedef struct pilha Pilha;

Pilha* criaPilha();
void liberaPilha(Pilha* pi);
int verificaPilhaVazia(Pilha* pi);
void empilha(Pilha* pi, int valor);
int desempilha(Pilha* pi);
int topoPilha(Pilha* pi);
void imprimePilha(Pilha* pi);
void separaParesImpares(Pilha* origem, Pilha* pares, Pilha* impares);

