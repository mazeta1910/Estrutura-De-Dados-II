typedef struct matheus Matheus;
typedef struct celula Celula;
typedef struct fila Fila;

Fila* criaFilaVazia();
void liberaFila(Fila* fi);
int verificaFilaVazia(Fila* fi);
void enfileiraChamado(Fila* fi, char* nomeUsuario, char* problema, char* prioridade);
void desenfileiraChamado(Fila* fi);
int buscaChamado(Fila* fi, char* nomeUsuario);
void imprimeFila(Fila* fi);

