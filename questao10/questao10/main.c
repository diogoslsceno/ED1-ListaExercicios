#include <stdio.h>
#include <stdlib.h>
#define TAM 1000

/*
    Questao 10 - Busca binaria de IDs de clientes (E-commerce)

    O vetor possui 1000 IDs de clientes organizados em ordem
    crescente. A busca binaria divide o intervalo de pesquisa
    pela metade a cada tentativa, verificando se o ID foi
    encontrado ou se deve continuar pela metade esquerda ou direita.
    A questão exige especificamente um vetor com 1000 IDs "rigorosamente
    ordenados de forma crescente", mas não especifica que o
    primeiro ID deveria ser 1000.
*/

// Aqui e procurado um ID usando busca binaria
int busca_binaria(int v[], int n, int id){
    int inicio = 0;
    int fim = n - 1;
    int meio;

    // Aqui continua enquanto houver elementos
    while(inicio <= fim){

        // Aqui calcula o meio do intervalo
        meio = (inicio + fim) / 2;

        // Aqui e verificado se encontrou o ID
        if(v[meio] == id){
            return meio;
        }

        // Aqui procura na metade direita
        if(id > v[meio]){
            inicio = meio + 1;
        }

        // Aqui procura na metade esquerda
        else{
            fim = meio - 1;
        }
    }

    // Cai aqui se ID não for encontrado
    return -1;
}

// Aqui e a funcao principal para testar o programa
int main(void){
    int clientes[TAM];
    int i;
    int id;
    int pos;

    // Aqui e criado os IDs ordenados de 1 ate 1000
    for(i = 0; i < TAM; i++){
        clientes[i] = i + 1;
    }

    // Aqui e lido o ID procurado
    printf("Digite o ID do cliente: ");
    scanf("%d", &id);

    // Aqui e realizada a busca
    pos = busca_binaria(clientes, TAM, id);

    // Aqui e verificado o resultado
    if(pos != -1){
        printf("Cliente encontrado na posicao %d.\n", pos);
        printf("Cliente ativo na base de dados.\n");
    }
    else{
        printf("Cliente nao encontrado.\n");
        printf("Cliente nao esta ativo na base de dados.\n");
    }
    return 0;
}
