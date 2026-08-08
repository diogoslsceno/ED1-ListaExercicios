#include <stdio.h>

/*
 * Questao 9 - Busca linear em posicoes de galpao (Logistica)
 *
 * O vetor com 15 codigos de barras nao esta ordenado, por isso
 * a busca precisa verificar cada posicao ate encontrar o codigo
 * ou chegar ao final sem resultado. Retorna o indice encontrado
 * ou -1 caso o codigo nao exista no galpao.
 */

#define TAM 15

int busca_linear(const int v[], int n, int chave)
{
    int i;

    for (i = 0; i < n; i++) {
        if (v[i] == chave)
            return i;
    }

    return -1; /* codigo nao encontrado */
}


void exibir_galpao(const int v[], int n)
{
    int i;
    printf("Posicoes do galpao:\n");
    for (i = 0; i < n; i++)
        printf("  [%2d] cod. %d\n", i, v[i]);
}


int main(void)
{
    /* Codigos armazenados sem ordenacao definida */
    int galpao[TAM] = {
        74823, 31045, 98761, 55210, 66780,
        12309, 47852, 83641, 29104, 71530,
        60492, 38175, 91284, 50637, 24918
    };

    int codigo, resultado;

    exibir_galpao(galpao, TAM);
    printf("\n");

    /* Busca de um codigo existente */
    codigo    = 83641;
    resultado = busca_linear(galpao, TAM, codigo);
    if (resultado != -1)
        printf("Codigo %d encontrado na posicao [%d]\n", codigo, resultado);
    else
        printf("Codigo %d nao encontrado no galpao\n", codigo);

    /* Busca de um codigo inexistente */
    codigo    = 99999;
    resultado = busca_linear(galpao, TAM, codigo);
    if (resultado != -1)
        printf("Codigo %d encontrado na posicao [%d]\n", codigo, resultado);
    else
        printf("Codigo %d nao encontrado no galpao\n", codigo);

    return 0;
}
