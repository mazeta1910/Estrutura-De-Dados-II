#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "convenios.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Pilha* pilhaConvenios = criaPilha();
    int opcao;
    char empresa[100], area[50];
    float desconto;
    
    // Cadastrando pelo menos 4 registros iniciais
    printf("=== CADASTRANDO CONVENIOS INICIAIS ===\n");
    empilhaConvenio(pilhaConvenios, "Farmacia Drogasil", "Saude", 15.0);
    empilhaConvenio(pilhaConvenios, "Academia Smart Fit", "Fitness", 20.0);
    empilhaConvenio(pilhaConvenios, "Restaurante Outback", "Alimentacao", 10.0);
    empilhaConvenio(pilhaConvenios, "Livraria Saraiva", "Educacao", 12.5);
    empilhaConvenio(pilhaConvenios, "Posto Shell", "Combustivel", 5.0);
    
    do
    {
        printf("\n=== SISTEMA DE CONVENIOS ===\n");
        printf("1 - Cadastrar novo convenio\n");
        printf("2 - Remover ultimo convenio\n");
        printf("3 - Buscar convenio\n");
        printf("4 - Listar todos os convenios\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1:
                printf("Digite o nome da empresa: ");
                scanf(" %[^\n]", empresa);
                
                printf("Escolha a area de atuacao:\n");
                printf("1 - Saude\n");
                printf("2 - Alimentacao\n");
                printf("3 - Educacao\n");
                printf("4 - Fitness\n");
                printf("5 - Combustivel\n");
                printf("6 - Tecnologia\n");
                printf("7 - Vestuario\n");
                printf("8 - Outros\n");
                printf("Opcao: ");
                int opcao_area;
                scanf("%d", &opcao_area);
                
                switch(opcao_area)
                {
                    case 1: strcpy(area, "Saude"); break;
                    case 2: strcpy(area, "Alimentacao"); break;
                    case 3: strcpy(area, "Educacao"); break;
                    case 4: strcpy(area, "Fitness"); break;
                    case 5: strcpy(area, "Combustivel"); break;
                    case 6: strcpy(area, "Tecnologia"); break;
                    case 7: strcpy(area, "Vestuario"); break;
                    case 8: strcpy(area, "Outros"); break;
                    default: 
                        printf("Opcao invalida! Usando 'Outros' como padrao.\n");
                        strcpy(area, "Outros");
                        break;
                }
                
                // Validação do desconto com loop
                do {
                    printf("Digite o desconto para associados (0-100%%): ");
                    if (scanf("%f", &desconto) != 1) {
                        printf("Erro: Digite apenas numeros!\n");
                        while(getchar() != '\n'); // Limpa buffer
                        desconto = -1; // Força repetição
                    } else if (desconto < 0 || desconto > 100) {
                        printf("Erro: Desconto deve estar entre 0%% e 100%%!\n");
                        desconto = -1; // Força repetição
                    }
                } while (desconto < 0 || desconto > 100);
                
                empilhaConvenio(pilhaConvenios, empresa, area, desconto);
                break;
                
            case 2:
                desempilhaConvenio(pilhaConvenios);
                break;
                
            case 3:
                printf("Digite o nome da empresa a ser buscada: ");
                scanf(" %[^\n]", empresa);
                if(buscaConvenio(pilhaConvenios, empresa))
                {
                    printf("Convenio com '%s' encontrado!\n", empresa);
                }
                else
                {
                    printf("Convenio com '%s' nao encontrado!\n", empresa);
                }
                break;
                
            case 4:
                imprimePilha(pilhaConvenios);
                break;
                
            case 5:
                printf("Saindo do sistema...\n");
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 5);
    
    liberaPilha(pilhaConvenios);
    
    return 0;
}

