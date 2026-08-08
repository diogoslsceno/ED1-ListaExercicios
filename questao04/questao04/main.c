#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

/*
    Questao 4 - Fila de pedidos da cozinha (Comercio)

    A fila armazena os pedidos da cozinha seguindo a ordem
    de chegada. Cada pedido possui um numero e o nome do prato.
    O programa permite inserir pedidos no final da fila e
    remover e exibir o primeiro pedido para ser preparado.
*/

// Aqui e representado um pedido
typedef struct{
    int numero_pedido;
    char nome_prato[100];
} Pedido;

// Aqui e representado a fila
typedef struct{
    Pedido v[MAX];
    int ini;
    int fim;
} Fila;

// Aqui que inicializa a fila
void inicializa(Fila* f){
    f->ini = 0;
    f->fim = 0;
}

// Aqui e verificacado se a fila esta vazia
int vazia(Fila* f){
    return f->ini == f->fim;
}

// Aqui e verificado se a fila esta cheia
int cheia(Fila* f){
    return f->fim == MAX;
}

// Aqui e inserido um pedido
void enfileira(Fila* f, int numero, char* prato){

    // Aqui e verificado se ha espaco
    if(cheia(f)){
        printf("Fila cheia!\n");
        return;
    }

    // Aqui e armazenado o pedido
    f->v[f->fim].numero_pedido = numero;
    strcpy(f->v[f->fim].nome_prato, prato);
    f->fim++;
}

// Aqui e removido e exibido o proximo pedido
void desenfileira(Fila* f){
    int i;

    // Aqui e verificado se a fila esta vazia
    if(vazia(f)){
        printf("Fila vazia!\n");
        return;
    }

    // Aqui e exibido o primeiro pedido
    printf("Proximo pedido:\n");
    printf("Numero: %d\n", f->v[f->ini].numero_pedido);
    printf("Prato: %s\n", f->v[f->ini].nome_prato);

    // Aqui e deslocado os pedidos
    for(i = f->ini; i < f->fim - 1; i++){
        f->v[i] = f->v[i + 1];
    }

    f->fim--;
}

// Aqui e a funcao principal para testar o programa
int main(void){
    Fila fila;
    // Aqui e inicializa a fila
    inicializa(&fila);
    // Aqui e adicionado os pedidos
    enfileira(&fila, 101, "Lasanha");
    enfileira(&fila, 102, "Hamburguer");
    enfileira(&fila, 103, "Pizza");
    // Aqui e atendido o proximo pedido
    desenfileira(&fila);
    return 0;
}
