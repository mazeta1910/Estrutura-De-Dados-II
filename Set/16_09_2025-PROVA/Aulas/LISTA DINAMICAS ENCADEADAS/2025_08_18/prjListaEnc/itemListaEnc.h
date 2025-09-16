#ifndef ITEMLISTAENC_H_INCLUDED
#define ITEMLISTAENC_H_INCLUDED

typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista * criaListaVazia();
void imprimeLista(Lista *lst);
Celula * buscaPorChave(Lista *lst, int chave);
int verificaListaVazia(Lista *lst);
void insereInicioLista(Lista *lst, int chave);
void insereFimLista(Lista *lst, int chave);
void insereMeioLista(Lista *lst, int chave, int x);
void liberaLista(Lista *lst);
void removeItem(Lista *lst, int x);

#endif // ITEMLISTAENC_H_INCLUDED
