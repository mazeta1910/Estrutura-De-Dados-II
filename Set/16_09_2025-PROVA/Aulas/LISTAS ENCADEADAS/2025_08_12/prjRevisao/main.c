#include <stdio.h>
#include <stdlib.h>

//Constante
#define _Meses 12

//Funções
int funcao1(); //com retorno e sem parâmetros
int funcao2(int a, char b); //com retorno e com parâmetros
void funcao3(); //sem retorno e sem parâmetros

void funcao4(int *vetInt); //com retorno e 1 parâmetro do tipo vetor de inteiro
void funcao5(int **matInt); //com retorno e 1 parâmetro do tipo matriz de inteiro


int main()
{
    //Tipos de dados usados em variáveis
    int varInt; //número inteiro
    float varFloat; //número com casas decimais de menor precisão
    double varDouble; //número com casas decimais de maior precisão
    char varChar; //1 caractere

    //Vetores
    int vetorInt[5]; //{0, 1 , 2 ,3 , 4}
    char vetorChar[5]; //{'a', 'b', 'c', 'd', 'e'}
    char vetorString[10]; //{'t','e','s','t','e','\0', , , ,}

    //Matrizes
    int matrizInt[3][2]; //3 linhas e 2 colunas
                        //indices: 0 a 2 para linhas, e 0 a 1 p/ colunas

    //Ponteiros
    int *ponteiroInt; //declaração de uma variável do tipo ponteiro
    ponteiroInt = &varInt; //atribuição de endereço de memória a um ponteiro

    *ponteiroInt = 5; //Acesso ao conteúdo de um ponteiro

    return 0;
}
