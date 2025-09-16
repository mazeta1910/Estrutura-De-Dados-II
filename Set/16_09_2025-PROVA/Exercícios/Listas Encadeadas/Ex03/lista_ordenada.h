typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista* criaLista();
void liberaLista(Lista* li);
int verificaListaVazia(Lista* li);
void insereLista(Lista* li, int valor);
void insereOrdenado(Lista* li, int valor);
void imprimeLista(Lista* li);
void transfereOrdenado(Lista* origem, Lista* destino);

