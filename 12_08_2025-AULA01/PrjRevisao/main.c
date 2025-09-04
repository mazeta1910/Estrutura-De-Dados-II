#include <stdio.h>
#include <stdlib.h>

//Constante
#define Meses 12

int main()
{

    //Tipo de dados:
    int varInt;
    float varFloat; // menor precisão
    double varDouble; // maior precisão
    char varChar;

    //Vetores
    int vetorInt[5];
    char vetorChar[5];
    char vetorString[6];

    //Matrinzes
    int matrizInt[3][2]; // 3 linhas e 2 colunas

    //Ponteiros
    int *ponteiroInt; // declaração de uma variável do tipo ponteiro
    ponteiroInt = &varInt; // atribuição de endereço de memória a um ponteiro;

    *ponteiroInt = 5; //Acesso ao conteúdo de um ponteiro

    /*Pilha: Topo só.

    Fila: Entra no fim, sai do início.

    Lista: Insere/remove em qualquer lugar.

    Deque: Insere/remove nas pontas.*/

    return 0;
}
