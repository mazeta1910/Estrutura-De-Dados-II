#include <stdio.h>
#include <stdlib.h>

//Constante
#define _Meses 12

//Fun��es
int funcao1(); //com retorno e sem par�metros
int funcao2(int a, char b); //com retorno e com par�metros
void funcao3(); //sem retorno e sem par�metros

void funcao4(int *vetInt); //com retorno e 1 par�metro do tipo vetor de inteiro
void funcao5(int **matInt); //com retorno e 1 par�metro do tipo matriz de inteiro


int main()
{
    //Tipos de dados usados em vari�veis
    int varInt; //n�mero inteiro
    float varFloat; //n�mero com casas decimais de menor precis�o
    double varDouble; //n�mero com casas decimais de maior precis�o
    char varChar; //1 caractere

    //Vetores
    int vetorInt[5]; //{0, 1 , 2 ,3 , 4}
    char vetorChar[5]; //{'a', 'b', 'c', 'd', 'e'}
    char vetorString[10]; //{'t','e','s','t','e','\0', , , ,}

    //Matrizes
    int matrizInt[3][2]; //3 linhas e 2 colunas
                        //indices: 0 a 2 para linhas, e 0 a 1 p/ colunas

    //Ponteiros
    int *ponteiroInt; //declara��o de uma vari�vel do tipo ponteiro
    ponteiroInt = &varInt; //atribui��o de endere�o de mem�ria a um ponteiro

    *ponteiroInt = 5; //Acesso ao conte�do de um ponteiro

    return 0;
}
