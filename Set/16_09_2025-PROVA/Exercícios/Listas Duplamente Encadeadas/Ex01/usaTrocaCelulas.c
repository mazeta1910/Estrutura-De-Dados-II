#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "inventario.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Deque* inventario = criaDeque();
    char regiao[100], especie[100];
    int quantidade;
    char resposta;
    
    printf("=== SISTEMA DE INVENTARIO DE ARVORES ===\n\n");
    
    do
    {
        printf("Informe a regiao que esta sendo inventariada: ");
        scanf(" %[^\n]", regiao);
        
        do
        {
            printf("Informe a especie de arvore que ira compor o inventario: ");
            scanf(" %[^\n]", especie);
            
            printf("Informe a quantidade de arvores desta especie que foram identificadas: ");
            scanf("%d", &quantidade);
            
            insereArvore(inventario, regiao, especie, quantidade);
            
            printf("\nDeseja armazenar mais dados para essa regiao? (S/N)");
            scanf(" %c", &resposta);
            
        } while(resposta == 'S' || resposta == 's');
        
        printf("Deseja armazenar dados de outra regiao? (S/N)");
        scanf(" %c", &resposta);
        
    } while(resposta == 'S' || resposta == 's');
    
    // Menu de opções adicionais
    do
    {
        printf("\n=== OPCOES DO SISTEMA ===\n");
        printf("1 - Visualizar inventario completo\n");
        printf("2 - Calcular porcentagens por regiao\n");
        printf("3 - Mostrar especie mais frequente\n");
        printf("4 - Desfazer ultimo cadastro\n");
        printf("5 - Adicionar mais dados\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");
        
        int opcao;
        scanf("%d", &opcao);
        
        switch(opcao)
        {
            case 1:
                imprimeInventario(inventario);
                break;
                
            case 2:
                calculaPorcentagens(inventario);
                break;
                
            case 3:
                especieMaisFrequente(inventario);
                break;
                
            case 4:
                removeUltimo(inventario);
                break;
                
            case 5:
                printf("Informe a regiao que esta sendo inventariada: ");
                scanf(" %[^\n]", regiao);
                
                do
                {
                    printf("Informe a especie de arvore que ira compor o inventario: ");
                    scanf(" %[^\n]", especie);
                    
                    printf("Informe a quantidade de arvores desta especie que foram identificadas: ");
                    scanf("%d", &quantidade);
                    
                    insereArvore(inventario, regiao, especie, quantidade);
                    
                    printf("\nDeseja armazenar mais dados para essa regiao? (S/N)");
                    scanf(" %c", &resposta);
                    
                } while(resposta == 'S' || resposta == 's');
                break;
                
            case 6:
                printf("Encerrando sistema de inventario...\n");
                
                // Mostra relatório final
                printf("\n=== RELATORIO FINAL ===\n");
                imprimeInventario(inventario);
                calculaPorcentagens(inventario);
                especieMaisFrequente(inventario);
                
                liberaDeque(inventario);
                return 0;
                
            default:
                printf("Opcao invalida!\n");
        }
        
        printf("\nDeseja continuar usando o sistema? (S/N)");
        scanf(" %c", &resposta);
        
    } while(resposta == 'S' || resposta == 's');
    
    // Relatório final
    printf("\n=== RELATORIO FINAL ===\n");
    imprimeInventario(inventario);
    calculaPorcentagens(inventario);
    especieMaisFrequente(inventario);
    
    liberaDeque(inventario);
    
    return 0;
}

