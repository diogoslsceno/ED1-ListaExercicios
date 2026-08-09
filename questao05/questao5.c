#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODIGO 30

// Cada no representa uma caixa; o ponteiro 'abaixo' aponta para a caixa anterior 
typedef struct No {
    char codigo_rastreio[MAX_CODIGO];
    struct No *abaixo;
} No;

typedef struct {
    No  *topo;   // referencia para a caixa do topo do palete
    int  altura; // quantidade de caixas empilhadas no momento
} Pilha;


void inicializa_pilha(Pilha *p)
{
    p->topo   = NULL;
    p->altura = 0;
}

int pilha_vazia(const Pilha *p)
{
    return (p->topo == NULL);
}


// Empilha uma nova caixa: o novo no aponta para o antigo topo e passa a ser o novo topo
void empilhar_caixa(Pilha *p, const char *codigo_rastreio)
{
    No *nova = (No *) malloc(sizeof(No));
    if (nova == NULL) {
        printf("Erro: memoria insuficiente.\n");
        return;
    }

    strncpy(nova->codigo_rastreio, codigo_rastreio, MAX_CODIGO - 1);
    nova->codigo_rastreio[MAX_CODIGO - 1] = '\0';

    nova->abaixo = p->topo;
    p->topo      = nova;
    p->altura++;

    printf("[+] Empilhada: %s (altura atual: %d)\n", nova->codigo_rastreio, p->altura);
}


// Remove a caixa do topo e expoe a que estava abaixo
void desempilhar_caixa(Pilha *p)
{
    No *removida;

    if (pilha_vazia(p)) {
        printf("Palete vazio.\n");
        return;
    }

    removida = p->topo;
    p->topo  = removida->abaixo;
    p->altura--;

    printf("[-] Retirada: %s (altura atual: %d)\n", removida->codigo_rastreio, p->altura);

    free(removida);
}


void exibir_pilha(const Pilha *p)
{
    No  *atual;
    int  pos = 1;

    if (pilha_vazia(p)) {
        printf("Palete vazio.\n");
        return;
    }

    printf("Estado do palete (topo -> base):\n");
    for (atual = p->topo; atual != NULL; atual = atual->abaixo)
        printf("  [%d] %s\n", pos++, atual->codigo_rastreio);
}


// Libera todas as caixas ainda na pilha
void liberar_pilha(Pilha *p)
{
    while (!pilha_vazia(p))
        desempilhar_caixa(p);
}


int main(void)
{
    Pilha palete;
    inicializa_pilha(&palete);

    empilhar_caixa(&palete, "BR-2024-001");
    empilhar_caixa(&palete, "BR-2024-002");
    empilhar_caixa(&palete, "BR-2024-003");
    empilhar_caixa(&palete, "BR-2024-004");

    printf("\n");
    exibir_pilha(&palete);

    printf("\nRetirando caixas para expedicao:\n");
    desempilhar_caixa(&palete);
    desempilhar_caixa(&palete);

    printf("\n");
    exibir_pilha(&palete);

    liberar_pilha(&palete);

    return 0;
}
