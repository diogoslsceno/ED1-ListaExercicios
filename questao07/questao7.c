#include <stdio.h>

#define N 8

void troca(float *a, float *b)
{
    float tmp = *a;
    *a = *b;
    *b = tmp;
}


void bubble_sort(float v[], int n)
{
    int i, j, trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        // Compara pares adjacentes e coloca o maior ao final do trecho nao ordenado
        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                troca(&v[j], &v[j + 1]);
                trocou = 1;
            }
        }

        // Se nenhuma troca ocorreu, o vetor ja esta ordenado
        if (!trocou)
            break;
    }
}


void exibir_precos(const float v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("  Pacote %d: R$ %.2f\n", i + 1, v[i]);
}


int main(void)
{
    float precos[N] = {1500.00, 980.50, 3200.00, 750.00,
                       2100.75, 1250.00, 450.90, 2800.00};

    printf("Precos antes da ordenacao:\n");
    exibir_precos(precos, N);

    bubble_sort(precos, N);

    printf("\nPrecos apos o Bubble Sort (crescente):\n");
    exibir_precos(precos, N);

    return 0;
}
