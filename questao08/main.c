#include <stdio.h>
#include <stdlib.h>

/*
    Questao 8 - Ordenacao de horarios (Comercio)

    O vetor armazena 10 horarios de chegada de fornecedores
    representados por minutos decorridos no dia. O programa
    utiliza o Insertion Sort para organizar os horarios em
    ordem cronologica crescente.
*/

// Aqui e ordenado o vetor com Insertion Sort
void insertion_sort(int v[], int n){
    int i;
    int j;
    int x;

    // Aqui e percorre o vetor
    for(i = 1; i < n; i++){

        // Aqui e guardado o elemento atual
        x = v[i];

        // Aqui e movido os elementos maiores
        for(j = i - 1; j >= 0 && v[j] > x; j--){
            v[j + 1] = v[j];
        }

        // Aqui e insere o elemento na posicao
        v[j + 1] = x;
    }
}

// Aqui e exibido o vetor
void imprime(int v[], int n){
    int i;

    // Aqui e percorrido o vetor
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}

// Aqui e a funcao principal para testar o programa
int main(void){
    int horarios[10] = {
        720,
        480,
        900,
        615,
        530,
        1020,
        450,
        840,
        660,
        570
    };

    printf("Horarios antes da ordenacao:\n");
    imprime(horarios, 10);

    // Aqui e ordenado os horarios
    insertion_sort(horarios, 10);

    printf("\nHorarios depois da ordenacao:\n");
    imprime(horarios, 10);
    return 0;
}
