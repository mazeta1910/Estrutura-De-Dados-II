#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "agenda.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Lista* agenda = criaLista();
    int opcao;
    char nome[100], telefone[20], email[100];
    
    // Cadastrando pelo menos 4 registros iniciais
    printf("=== CADASTRANDO CONTATOS INICIAIS ===\n");
    insereLista(agenda, "Ana Silva", "(11) 99999-1111", "ana.silva@email.com");
    insereLista(agenda, "Carlos Santos", "(11) 88888-2222", "carlos.santos@email.com");
    insereLista(agenda, "Maria Oliveira", "(11) 77777-3333", "maria.oliveira@email.com");
    insereLista(agenda, "João Pereira", "(11) 66666-4444", "joao.pereira@email.com");
    
    do
    {
        printf("\n=== MENU AGENDA TELEFONICA ===\n");
        printf("1 - Inserir novo contato\n");
        printf("2 - Excluir contato\n");
        printf("3 - Buscar contato\n");
        printf("4 - Imprimir todos os contatos\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1:
                printf("Digite o nome do contato: ");
                scanf(" %[^\n]", nome);
                printf("Digite o telefone: ");
                scanf(" %[^\n]", telefone);
                printf("Digite o e-mail: ");
                scanf(" %[^\n]", email);
                insereLista(agenda, nome, telefone, email);
                break;
                
            case 2:
                printf("Digite o nome do contato a ser removido: ");
                scanf(" %[^\n]", nome);
                removeLista(agenda, nome);
                break;
                
            case 3:
                printf("Digite o nome do contato a ser buscado: ");
                scanf(" %[^\n]", nome);
                if(buscaLista(agenda, nome))
                {
                    printf("Contato encontrado!\n");
                }
                else
                {
                    printf("Contato nao encontrado!\n");
                }
                break;
                
            case 4:
                imprimeLista(agenda);
                break;
                
            case 5:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 5);
    
    liberaLista(agenda);
    
    return 0;
}

