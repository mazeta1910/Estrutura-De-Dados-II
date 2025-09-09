typedef struct data Data;

Data *dataNova(int d, int m, int a);
Data *dataHoje(void);
void imprimirData(Data *dt);
void liberarData(Data *dt);

