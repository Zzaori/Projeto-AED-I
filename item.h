#ifndef ITEM_H
#define ITEM_H

typedef struct {
    int id;
    char nome[50];
    char status[100];
} Item;

struct no {
    Item dado;
    struct no* prox;
};

typedef struct no No;

struct lista {
    No* inicio;
};

typedef struct lista Lista;

int realizarLogin(char *usuario, char *senha);
int verificarEmail(char *email);
void mensagemBoasVindas();
void apresentarMenu();
void cadastrarItem(Lista *lista);
void salvarItens(Lista *lista);
void carregarItens(Lista *lista);
void editarItem(Lista *lista);
void excluirItem(Lista *lista);
void buscarItem(Lista *lista);
void autorizado();
void contencaoItens(Lista *lista);
void ordenarPorID(Lista *lista);

#endif
