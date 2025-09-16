#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "chamados.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Fila* filaChamados = criaFilaVazia();
    int opcao;
    char nomeUsuario[100], problema[200], prioridade[20];
    
    // Cadastrando pelo menos 4 registros iniciais
    printf("=== CADASTRANDO CHAMADOS INICIAIS ===\n");
    enfileiraChamado(filaChamados, "Ana Silva", "Computador nao liga", "Alta");
    enfileiraChamado(filaChamados, "Carlos Santos", "Internet lenta", "Media");
    enfileiraChamado(filaChamados, "Maria Oliveira", "Impressora travada", "Baixa");
    enfileiraChamado(filaChamados, "Joao Pereira", "Sistema travando", "Alta");
    enfileiraChamado(filaChamados, "Paula Costa", "Email nao funciona", "Media");
    
    do
    {
        printf("\n=== SISTEMA DE CHAMADOS DE SUPORTE ===\n");
        printf("1 - Abrir novo chamado\n");
        printf("2 - Atender proximo chamado\n");
        printf("3 - Buscar chamado por usuario\n");
        printf("4 - Visualizar fila de chamados\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1:
                printf("Digite o nome do usuario: ");
                scanf(" %[^\n]", nomeUsuario);
                
                printf("Descreva o problema: ");
                scanf(" %[^\n]", problema);
                
                printf("Escolha a prioridade:\n");
                printf("1 - Alta\n");
                printf("2 - Media\n");
                printf("3 - Baixa\n");
                printf("Opcao: ");
                int opcao_prioridade;
                scanf("%d", &opcao_prioridade);
                
                switch(opcao_prioridade)
                {
                    case 1: strcpy(prioridade, "Alta"); break;
                    case 2: strcpy(prioridade, "Media"); break;
                    case 3: strcpy(prioridade, "Baixa"); break;
                    default: 
                        printf("Opcao invalida! Usando 'Media' como padrao.\n");
                        strcpy(prioridade, "Media");
                        break;
                }
                
                enfileiraChamado(filaChamados, nomeUsuario, problema, prioridade);
                break;
                
            case 2:
                desenfileiraChamado(filaChamados);
                break;
                
            case 3:
                printf("Digite o nome do usuario a ser buscado: ");
                scanf(" %[^\n]", nomeUsuario);
                if(buscaChamado(filaChamados, nomeUsuario))
                {
                    printf("Chamado de '%s' encontrado na fila!\n", nomeUsuario);
                }
                else
                {
                    printf("Nenhum chamado de '%s' encontrado na fila.\n", nomeUsuario);
                }
                break;
                
            case 4:
                imprimeFila(filaChamados);
                break;
                
            case 5:
                printf("Encerrando sistema de chamados...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 5);
    
    liberaFila(filaChamados);
    
    return 0;
}

