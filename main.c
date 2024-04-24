#include <stdio.h>
#include <stdlib.h>
#include "item.h"

// Function declaration for listarItens
void listarItens(Lista *lista);
void ordenarPorID(Lista *lista);

int main() {
    char usuario[50];
    char senha[50];
    char email[80];
    Lista listaItens;
    listaItens.inicio = NULL;
    int opcao;

    printf("\nBem-vindo à HEX Selos Magickos - Controle de Itens Anômalos\n");

    // Realizar login
    do {
        printf("Usuário: ");
        scanf("%s", usuario);
        printf("Senha: ");
        scanf("%s", senha);
    } while (!realizarLogin(usuario, senha));

    // Verificar e-mail
    do {
        printf("Email: ");
        scanf("%s", email);
    } while (!verificarEmail(email));

    // Carregar itens do arquivo binário
    carregarItens(&listaItens);

    // Mensagem de boas-vindas
    mensagemBoasVindas();

    // Loop do menu de opções
    do {
        apresentarMenu();
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarItem(&listaItens);
                salvarItens(&listaItens);
                break;
            case 2:
                listarItens(&listaItens); 
                break;
            case 3:
                editarItem(&listaItens);
                salvarItens(&listaItens);
                break;
            case 4:
                excluirItem(&listaItens);
                salvarItens(&listaItens);
                break;
            case 5:
                buscarItem(&listaItens);
                break;
            case 6:
                autorizado();
                break;
            case 7:
                contencaoItens(&listaItens);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
