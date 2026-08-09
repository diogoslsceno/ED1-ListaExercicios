#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

// Cada no representa um visitante na fila 
typedef struct No {
    char nome[MAX_NOME];
    int  idade;
    struct No *prox;
} No;

/*A fila mantem dois ponteiros para evitar percorrer
  a lista toda ao inserir no fim.*/
typedef struct {
    No *inicio; //proximo a ser atendido 
    No *fim;    // ultimo que entrou  
} Fila;


void inicializa_fila(Fila *f)
{
    f->inicio = NULL;
    f->fim    = NULL;
}

int fila_vazia(const Fila *f)
{
    return (f->inicio == NULL);
}


// Insere um novo turista no fim da fila 
void enfileirar_turista(Fila *f, const char *nome, int idade)
{
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }

    strncpy(novo->nome, nome, MAX_NOME - 1);
    novo->nome[MAX_NOME - 1] = '\0';
    novo->idade = idade;
    novo->prox  = NULL;

    if (fila_vazia(f)) {
        f->inicio = novo;
        f->fim    = novo;
    } else {
        f->fim->prox = novo; // encadeia apos o ultimo elemento atual
        f->fim       = novo;
    }

    printf("[+] %s (%d anos) entrou na fila\n", novo->nome, novo->idade);
}


// Remove o turista do inicio da fila e exibe quem foi atendido
void atender_turista(Fila *f)
{
    No *atendido;

    if (fila_vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    atendido  = f->inicio;
    f->inicio = atendido->prox;

    // Se a fila ficou vazia, fim tambem precisa ser NULL 
    if (f->inicio == NULL)
        f->fim = NULL;

    printf("[-] %s (%d anos) foi atendido\n", atendido->nome, atendido->idade);

    free(atendido);
}


void exibir_fila(const Fila *f)
{
    No  *atual;
    int  pos = 1;

    if (fila_vazia(f)) {
        printf("Nenhum turista na fila.\n");
        return;
    }

    printf("Fila da montanha-russa:\n");
    for (atual = f->inicio; atual != NULL; atual = atual->prox)
        printf("  %d. %s - %d anos\n", pos++, atual->nome, atual->idade);
}


// Libera os nos restantes da fila
void liberar_fila(Fila *f)
{
    while (!fila_vazia(f))
        atender_turista(f);
}


int main(void)
{
    Fila fila;
    inicializa_fila(&fila);

    enfileirar_turista(&fila, "Ana",     25);
    enfileirar_turista(&fila, "Bruno",   17);
    enfileirar_turista(&fila, "Carla",   32);
    enfileirar_turista(&fila, "Daniel",  45);
    enfileirar_turista(&fila, "Eduarda", 22);

    printf("\n");
    exibir_fila(&fila);

    printf("\nAtendendo os dois primeiros:\n");
    atender_turista(&fila);
    atender_turista(&fila);

    printf("\n");
    exibir_fila(&fila);

    liberar_fila(&fila);

    return 0;
}
