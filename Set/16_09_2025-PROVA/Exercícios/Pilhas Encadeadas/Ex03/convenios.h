typedef struct matheus Matheus;
typedef struct celula Celula;
typedef struct pilha Pilha;

Pilha* criaPilha();
void liberaPilha(Pilha* pi);
int verificaPilhaVazia(Pilha* pi);
void empilhaConvenio(Pilha* pi, char* empresa, char* area, float desconto);
void desempilhaConvenio(Pilha* pi);
int buscaConvenio(Pilha* pi, char* empresa);
void imprimePilha(Pilha* pi);

