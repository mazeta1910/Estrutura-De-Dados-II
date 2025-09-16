typedef struct noticia Noticia;
typedef struct celula Celula;
typedef struct deque Deque;

Deque* criaDeque();
void liberaDeque(Deque* dq);
int verificaDequeVazio(Deque* dq);
void insereInicio(Deque* dq, char* titulo, char* conteudo, char* classificacao, char* autor);
void insereFim(Deque* dq, char* titulo, char* conteudo, char* classificacao, char* autor);
void removeInicio(Deque* dq);
void removeFim(Deque* dq);
void imprimeDeque(Deque* dq);
void estatisticasClassificacao(Deque* dq);

