typedef struct arvore Arvore;
typedef struct celula Celula;
typedef struct deque Deque;

Deque* criaDeque();
void liberaDeque(Deque* dq);
int verificaDequeVazio(Deque* dq);
void insereArvore(Deque* dq, char* regiao, char* especie, int quantidade);
void removeUltimo(Deque* dq);
void imprimeInventario(Deque* dq);
void calculaPorcentagens(Deque* dq);
void especieMaisFrequente(Deque* dq);
Arvore* buscaEspecieRegiao(Deque* dq, char* regiao, char* especie);

