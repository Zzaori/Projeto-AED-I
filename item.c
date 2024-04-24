#include "item.h"
#include <stdio.h>
#include <stdlib.h>

void inserirOrdenado(Lista* lista, Item item) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->dado = item;
    novo->prox = NULL;

    if (lista->inicio == NULL || item.id < lista->inicio->dado.id) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
    } else {
        No* atual = lista->inicio;
        while (atual->prox != NULL && atual->prox->dado.id < item.id) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

void ordenarPorID(Lista* lista) {
    Lista listaOrdenada;
    listaOrdenada.inicio = NULL;

    No* atual = lista->inicio;
    while (atual != NULL) {
        No* prox = atual->prox;
        inserirOrdenado(&listaOrdenada, atual->dado);
        atual = prox;
    }

    lista->inicio = listaOrdenada.inicio;
}

void exibirLista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        printf("\nID: %d\n", atual->dado.id);
        printf("Nome: %s\n", atual->dado.nome);
        printf("Status: %s\n", atual->dado.status);
        atual = atual->prox;
    }
}

int realizarLogin(char *usuario, char *senha) {
    char usuarioCorreto[] = "usuario";
    char senhaCorreta[] = "senha";

    int i = 0;
    while (usuario[i] == usuarioCorreto[i] && usuario[i] != '\0') {
        i++;
    }
    if (usuario[i] == '\0' && senha[0] == senhaCorreta[0]) {
        printf("\nLogin realizado com sucesso.\n");
    } else {
        printf("\nSenha ou usuário inválido.\n");
    }
}

int verificarEmail(char *email) {
    int i = 0, count = 0;
    while (email[i] != '\0') {
        if (email[i] == '@') {
            count++;
        }
        i++;
    }
    if (count == 1 && i < 80) {
        return 1;
    } else {
        printf("\nEmail inválido.\n");
        return 0;
    }
}

void mensagemBoasVindas() {
    printf("\nBem-vindo, Agente!\n");
}

void apresentarMenu() {
    printf("\nMenu de Opções:\n");
    printf("1 - Cadastrar Item\n");
    printf("2 - Listar Itens\n");
    printf("3 - Editar Item\n");
    printf("4 - Excluir Item\n");
    printf("5 - Buscar Item\n");
    printf("6 - Somente Pessoal Autorizado\n");
    printf("7 - Contenção\n");
    printf("0 - Sair\n");
}

void cadastrarItem(Lista *lista) {
    Item novoItem;
    printf("ID do Item: ");
    scanf("%d", &novoItem.id);
    printf("Nome do Item: ");
    scanf("%s", novoItem.nome);
    printf("Status do Item: ");
    scanf("%s", novoItem.status);

    inserirOrdenado(lista, novoItem);
}

void salvarItens(Lista *lista) {
    FILE *arquivo;
    arquivo = fopen("itens.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    No *atual = lista->inicio;
    while (atual != NULL) {
        fwrite(&(atual->dado), sizeof(Item), 1, arquivo);
        atual = atual->prox;
    }

    fclose(arquivo);
}

void carregarItens(Lista *lista) {
    FILE *arquivo;
    arquivo = fopen("itens.bin", "rb");
    if (arquivo == NULL) {
        printf("Arquivo de itens não encontrado. Criando novo arquivo.\n");
        return;
    }

    Item item;
    while (fread(&item, sizeof(Item), 1, arquivo)) {
        inserirOrdenado(lista, item);
    }

    fclose(arquivo);
}

void editarItem(Lista *lista) {
    int id;
    printf("ID do Item a ser editado: ");
    scanf("%d", &id);

    No *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dado.id == id) {
            printf("Novo Nome do Item: ");
            scanf("%s", atual->dado.nome);
            printf("Novo Status do Item: ");
            scanf("%s", atual->dado.status);
            printf("\nItem editado com sucesso.\n");
            return;
        }
        atual = atual->prox;
    }
    printf("\nItem não encontrado.\n");
}

void excluirItem(Lista *lista) {
    int id;
    printf("ID do Item a ser excluído: ");
    scanf("%d", &id);

    No *anterior = NULL;
    No *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->dado.id == id) {
            if (anterior == NULL) {
                lista->inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("\nItem excluído com sucesso.\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("\nItem não encontrado.\n");
}

void buscarItem(Lista *lista) {
    char nome[50];
    printf("Nome do Item a ser buscado: ");
    scanf("%s", nome);

    No *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dado.nome, nome) == 0) {
            printf("\nID: %d\n", atual->dado.id);
            printf("Nome: %s\n", atual->dado.nome);
            printf("Status: %s\n", atual->dado.status);
            return;
        }
        atual = atual->prox;
    }
    printf("\nItem não encontrado.\n");
}

void autorizado() {
    printf("\n************ ACEITAS. Bem-vindo C5-X. Você tem (1) Nova Mensagem.\n");
    printf("\nDevido a preocupações sobre outra possível instância anômala, para manter o controle da operação em caso de comprometimento do QG, os recrutas da Sítio-13 ​​receberam permissão adequada. Esta permissão afeta indefinidamente a operação ██████████.\n");
    printf("\n -O Administrador.\n");
}

void contencaoItens(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        printf("\nIniciando contenção do Item %s - ID: %d...\n", atual->dado.nome, atual->dado.id);
        printf("Item contido com sucesso.\n");
        atual = atual->prox;
    }
    printf("\nTodos os itens anômalos foram contidos com sucesso.\n");
}

void listarItens(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        printf("ID: %d\n", atual->dado.id);
        printf("Nome: %s\n", atual->dado.nome);
        printf("Status: %s\n", atual->dado.status);
        atual = atual->prox;
    }
}
