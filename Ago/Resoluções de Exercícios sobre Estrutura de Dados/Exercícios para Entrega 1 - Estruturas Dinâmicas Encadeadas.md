# Exercícios para Entrega 1 - Estruturas Dinâmicas Encadeadas

## Exercício 1 - TAD Lista Encadeada para Jogos Digitais

### Arquivos:
- `jogos.h` - Arquivo de cabeçalho com typedefs e protótipos
- `jogos.c` - Arquivo de implementação com structs e funções
- `usa_jogos.c` - Arquivo principal com menu e função main

### Compilação:
```bash
gcc -o jogos jogos.c usa_jogos.c
```

### Execução:
```bash
./jogos
```

### Funcionalidades:
- Inserir novo jogo (sem repetição de código)
- Excluir jogo por código
- Buscar jogo por código
- Imprimir todos os jogos
- Copiar jogos com estado "Finalizado"
- Menu interativo

## Exercício 2 - TAD Data + Pilha Encadeada para Cursos Online

### Arquivos:
- `Data.h` - Arquivo de cabeçalho do TAD Data
- `Data.c` - Arquivo de implementação do TAD Data
- `cursos.h` - Arquivo de cabeçalho do TAD Pilha de Cursos
- `cursos.c` - Arquivo de implementação do TAD Pilha de Cursos
- `usa_cursos.c` - Arquivo principal com menu e função main

### Compilação:
```bash
gcc -o cursos Data.c cursos.c usa_cursos.c
```

### Execução:
```bash
./cursos
```

### Funcionalidades:
- Inserir novo curso (com data de conclusão informada e data de cadastro automática)
- Excluir curso (seguindo regra LIFO da pilha)
- Imprimir todos os cursos
- Menu interativo
- Uso do TAD Data para datas

## Observações:
- Todos os TADs seguem o conceito de encapsulamento
- Estruturas internas não são acessíveis externamente
- Exercício 1 usa Lista Encadeada
- Exercício 2 usa Pilha Encadeada (estrutura diferente conforme solicitado)

