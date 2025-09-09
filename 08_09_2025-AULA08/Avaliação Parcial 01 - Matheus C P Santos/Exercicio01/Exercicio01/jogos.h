typedef struct jogo Jogo;
typedef struct celula Celula;
typedef struct lista Lista;

Lista* criaLista();
void liberaLista(Lista* li);
int verificaListaVazia(Lista* li);
void insereLista(Lista* li, char* nome, char* plataforma, int ano, char* estado);
void removeLista(Lista* li, char* codigo);
int buscaLista(Lista* li, char* codigo);
void imprimeLista(Lista* li);
Lista* copiaFinalizados(Lista* li);
char* geraProximoCodigo(Lista* li, char* plataforma);

