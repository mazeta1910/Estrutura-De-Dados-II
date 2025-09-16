#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "jornal.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Deque* jornalDigital = criaDeque();
    int opcao;
    char titulo[150], conteudo[500], classificacao[30], autor[100];
    
    // Cadastrando algumas notícias iniciais para demonstração
    printf("=== INICIALIZANDO JORNAL COM NOTICIAS EXEMPLO ===\n");
    insereFim(jornalDigital, "Nova Cafeteria Inaugurada", 
              "A empresa inaugurou uma nova cafeteria no 3o andar com opcoes veganas.", 
              "Infraestrutura", "RH Comunicacao");
    
    insereFim(jornalDigital, "Resultado Trimestral Positivo", 
              "A empresa apresentou crescimento de 15% no ultimo trimestre.", 
              "Financeiro", "Diretoria");
    
    insereFim(jornalDigital, "Campeonato de Futebol Interno", 
              "Inscricoes abertas para o campeonato de futebol entre departamentos.", 
              "Esporte", "Comite Social");
    
    insereInicio(jornalDigital, "URGENTE: Manutencao do Sistema", 
                 "Sistema principal ficara fora do ar das 18h as 20h hoje.", 
                 "TI", "Equipe Tecnica");
    
    insereFim(jornalDigital, "Workshop de Inovacao", 
              "Palestra sobre tendencias tecnologicas na proxima sexta-feira.", 
              "Educacao", "Departamento P&D");
    
    do
    {
        printf("\n=== JORNAL DIGITAL DA EMPRESA ===\n");
        printf("1 - Adicionar noticia normal (fim da fila)\n");
        printf("2 - Adicionar noticia PRIORITARIA (inicio da fila)\n");
        printf("3 - Remover primeira noticia\n");
        printf("4 - Remover ultima noticia\n");
        printf("5 - Visualizar todas as noticias\n");
        printf("6 - Estatisticas por classificacao\n");
        printf("7 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1:
                printf("Digite o titulo da noticia: ");
                scanf(" %[^\n]", titulo);
                
                printf("Digite o conteudo da noticia: ");
                scanf(" %[^\n]", conteudo);
                
                printf("Escolha a classificacao:\n");
                printf("1 - Financeiro\n");
                printf("2 - RH\n");
                printf("3 - TI\n");
                printf("4 - Esporte\n");
                printf("5 - Educacao\n");
                printf("6 - Infraestrutura\n");
                printf("7 - Cultura\n");
                printf("8 - Outros\n");
                printf("Opcao: ");
                int opcao_class;
                scanf("%d", &opcao_class);
                
                switch(opcao_class)
                {
                    case 1: strcpy(classificacao, "Financeiro"); break;
                    case 2: strcpy(classificacao, "RH"); break;
                    case 3: strcpy(classificacao, "TI"); break;
                    case 4: strcpy(classificacao, "Esporte"); break;
                    case 5: strcpy(classificacao, "Educacao"); break;
                    case 6: strcpy(classificacao, "Infraestrutura"); break;
                    case 7: strcpy(classificacao, "Cultura"); break;
                    case 8: strcpy(classificacao, "Outros"); break;
                    default: 
                        printf("Opcao invalida! Usando 'Outros' como padrao.\n");
                        strcpy(classificacao, "Outros");
                        break;
                }
                
                printf("Digite o nome do autor: ");
                scanf(" %[^\n]", autor);
                
                insereFim(jornalDigital, titulo, conteudo, classificacao, autor);
                break;
                
            case 2:
                printf("=== NOTICIA PRIORITARIA ===\n");
                printf("Digite o titulo da noticia: ");
                scanf(" %[^\n]", titulo);
                
                printf("Digite o conteudo da noticia: ");
                scanf(" %[^\n]", conteudo);
                
                printf("Escolha a classificacao:\n");
                printf("1 - Financeiro\n");
                printf("2 - RH\n");
                printf("3 - TI\n");
                printf("4 - Esporte\n");
                printf("5 - Educacao\n");
                printf("6 - Infraestrutura\n");
                printf("7 - Cultura\n");
                printf("8 - Outros\n");
                printf("Opcao: ");
                int opcao_class2;
                scanf("%d", &opcao_class2);
                
                switch(opcao_class2)
                {
                    case 1: strcpy(classificacao, "Financeiro"); break;
                    case 2: strcpy(classificacao, "RH"); break;
                    case 3: strcpy(classificacao, "TI"); break;
                    case 4: strcpy(classificacao, "Esporte"); break;
                    case 5: strcpy(classificacao, "Educacao"); break;
                    case 6: strcpy(classificacao, "Infraestrutura"); break;
                    case 7: strcpy(classificacao, "Cultura"); break;
                    case 8: strcpy(classificacao, "Outros"); break;
                    default: 
                        printf("Opcao invalida! Usando 'Outros' como padrao.\n");
                        strcpy(classificacao, "Outros");
                        break;
                }
                
                printf("Digite o nome do autor: ");
                scanf(" %[^\n]", autor);
                
                insereInicio(jornalDigital, titulo, conteudo, classificacao, autor);
                break;
                
            case 3:
                removeInicio(jornalDigital);
                break;
                
            case 4:
                removeFim(jornalDigital);
                break;
                
            case 5:
                imprimeDeque(jornalDigital);
                break;
                
            case 6:
                estatisticasClassificacao(jornalDigital);
                break;
                
            case 7:
                printf("Encerrando jornal digital...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 7);
    
    liberaDeque(jornalDigital);
    
    return 0;
}

