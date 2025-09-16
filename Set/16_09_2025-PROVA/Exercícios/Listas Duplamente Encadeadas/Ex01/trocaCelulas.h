typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista* criaLista();
void liberaLista(Lista* li);
int verificaListaVazia(Lista* li);
void insereLista(Lista* li, int chave, char* dados);
void removeLista(Lista* li, int chave);
Celula* buscaCelula(Lista* li, int chave);
void imprimeLista(Lista* li);
void imprimeListaReversa(Lista* li);
void trocaCelulas(Lista* li, int chave1, int chave2);
