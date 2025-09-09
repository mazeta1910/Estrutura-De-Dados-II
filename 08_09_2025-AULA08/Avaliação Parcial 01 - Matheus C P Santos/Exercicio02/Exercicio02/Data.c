#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Data.h"

struct data
{
    int dia;
    int mes;
    int ano;
};

Data *dataNova(int d, int m, int a)
{
    Data *dt = malloc(sizeof(Data));
    if(dt != NULL)
    {
        dt->dia = d;
        dt->mes = m;
        dt->ano = a;
    }
    return dt;
}

// função para obter a data de hoje a partir da data do sistema operacional
Data *dataHoje(void)
{
    Data *dt = malloc(sizeof(Data));
    time_t tempo;
    struct tm *hj;
    tempo = time(NULL); // obtem o tempo corrente
    hj = localtime(&tempo); // obtem a data do sistema operacional
    dt->dia = hj->tm_mday;
    dt->mes = hj->tm_mon + 1;
    dt->ano = hj->tm_year + 1900;
    return(dt);
}

void imprimirData(Data *dt)
{
    if(dt != NULL)
    {
        printf("%02d/%02d/%04d", dt->dia, dt->mes, dt->ano);
    }
}

void liberarData(Data *dt)
{
    if(dt != NULL)
    {
        free(dt);
    }
}

