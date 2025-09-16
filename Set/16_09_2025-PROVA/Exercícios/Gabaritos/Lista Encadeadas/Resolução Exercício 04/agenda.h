typedef struct matheus Matheus;
typedef struct celula Celula;
typedef struct lista Lista;

Lista* criaLista();
void liberaLista(Lista* li);
int verificaListaVazia(Lista* li);
void insereLista(Lista* li, char* nome, char* telefone, char* email);
void removeLista(Lista* li, char* nome);
int buscaLista(Lista* li, char* nome);
void imprimeLista(Lista* li);

