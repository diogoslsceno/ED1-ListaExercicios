#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

/*
    Questao 2 - Lista sequencial de paradas (Logistica)

    A lista armazena as paradas de uma rota, contendo o nome
    do bairro e o prazo da entrega em minutos. O programa
    permite inserir novas paradas e remover uma parada pelo
    nome do bairro quando a entrega for concluida.
*/

// Aqui representa uma parada
typedef struct{
    char nome_bairro[100];
    int prazo_minutos;
} Parada;

// Aqui representa a lista
typedef struct{
    Parada v[MAX];
    int n;
} Lista;

// Aqui inicializa a lista
void inicializa(Lista* l){
    l->n = 0;
}

// Aqui insere uma parada
void insere(Lista* l, char* bairro, int prazo){

    // Aqui verifica se ha espaco
    if(l->n == MAX){
        printf("Lista cheia!\n");
        return;
    }

    // Aqui armazena os dados
    strcpy(l->v[l->n].nome_bairro, bairro);
    l->v[l->n].prazo_minutos = prazo;
    l->n++;
}

// Aqui remove uma parada pelo bairro
void remove_parada(Lista* l, char* bairro){
    int i;
    int pos = -1;

    // Aqui procura o bairro
    for(i = 0; i < l->n; i++){
        if(strcmp(l->v[i].nome_bairro, bairro) == 0){
            pos = i;
            break;
        }
    }

    // Aqui verifica se encontrou
    if(pos == -1){
        printf("Parada nao encontrada!\n");
        return;
    }

    // Aqui desloca os elementos
    for(i = pos; i < l->n - 1; i++){
        l->v[i] = l->v[i + 1];
    }

    l->n--;
    printf("Parada removida com sucesso!\n");
}

// Aqui ele exibe as paradas
void imprime(Lista* l){
    int i;

    // Aqui ele percorre a lista
    for(i = 0; i < l->n; i++){
        printf("Bairro: %s | Prazo: %d minutos\n",
               l->v[i].nome_bairro,
               l->v[i].prazo_minutos);
    }
}

// Aqui e a funcao principal para testar o programa
int main(void){
    Lista rota;
    // Aqui inicializa a rota
    inicializa(&rota);
    // Aqui adiciona as paradas
    insere(&rota, "Centro", 30);
    insere(&rota, "Marco", 45);
    insere(&rota, "Umarizal", 20);
    insere(&rota, "Pedreira", 50);

    printf("Rota antes da entrega:\n");
    imprime(&rota);
    // Aqui remove uma parada concluida
    remove_parada(&rota, "Marco");
    printf("\nRota apos a entrega:\n");
    imprime(&rota);
    return 0;
}
