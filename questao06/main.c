#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*
    Questao 6 - Sistema de Desfazer de preco (E-commerce)

    A pilha armazena o preco anterior de cada alteracao
    realizada no cadastro de um produto. Quando o usuario
    solicita o desfazer, o ultimo preco armazenado e retirado
    da pilha e restaurado, seguindo a regra LIFO.
*/

// Aqui e representa uma acao
typedef struct{
    float preco_antigo;
} Acao;

// Aqui representa a pilha
typedef struct{
    Acao v[MAX];
    int n;
} Pilha;

// Aqui e inicializada a pilha
void inicializa(Pilha* p){
    p->n = 0;
}

// Aqui e verificada se esta vazia
int vazia(Pilha* p){
    return p->n == 0;
}

// Aqui e verificada se esta cheia
int cheia(Pilha* p){
    return p->n == MAX;
}

// Aqui e guardado o preco antigo
void empilha(Pilha* p, float preco_antigo){

    // Aqui e verifica se ha espaco
    if(cheia(p)){
        printf("Pilha cheia!\n");
        return;
    }

    // Aqui e armazenado o preco
    p->v[p->n].preco_antigo = preco_antigo;
    p->n++;
}

// Aqui e recuperado o ultimo preco
float desempilha(Pilha* p){

    // Aqui e verificado se ha historico
    if(vazia(p)){
        printf("Nao ha alteracoes para desfazer!\n");
        return -1;
    }

    p->n--;
    return p->v[p->n].preco_antigo;
}

// Aqui e alterado o preco
void alterar_preco(Pilha* p, float* preco, float novo_preco){

    // Aqui e guardado o preco atual
    empilha(p, *preco);

    // Aqui atualiza o preco
    *preco = novo_preco;
    printf("Preco alterado para R$ %.2f\n", *preco);
}

// Aqui desfaz a ultima alteracao
void desfazer(Pilha* p, float* preco){
    // Aqui verifica se ha alteracao
    if(vazia(p)){
        printf("Nao ha alteracoes para desfazer!\n");
        return;
    }

    // Aqui ele restaura o preco anterior
    *preco = desempilha(p);
    printf("Alteracao desfeita. Preco atual: R$ %.2f\n", *preco);
}

// Aqui e a funcao principal para testar o programa
int main(void){
    Pilha historico;
    float preco = 100.00;

    // Aqui e inicializado o historico
    inicializa(&historico);

    printf("Preco inicial: R$ %.2f\n", preco);

    // Aqui e realizado as alteracoes
    alterar_preco(&historico, &preco, 120.00);
    alterar_preco(&historico, &preco, 150.00);
    alterar_preco(&historico, &preco, 180.00);

    printf("\nDesfazendo:\n");

    // Aqui desfaz as alteracoes
    desfazer(&historico, &preco);
    desfazer(&historico, &preco);
    desfazer(&historico, &preco);
    return 0;
}
