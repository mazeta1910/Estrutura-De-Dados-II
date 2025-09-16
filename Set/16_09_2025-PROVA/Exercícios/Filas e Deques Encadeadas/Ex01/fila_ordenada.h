typedef struct item Item;
typedef struct celula Celula;
typedef struct fila Fila;

Fila* criaFilaVazia();
void liberaFila(Fila* fi);
int verificaFilaVazia(Fila* fi);
void enfileira(Fila* fi, int valor);
void desenfileira(Fila* fi);
void imprimeFila(Fila* fi);
int verificaFilaOrdenada(Fila* fi);

