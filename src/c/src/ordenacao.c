#include "ordenacao.h"

// Função de ordenação Counting Sort
int* ordenacaoCounting(int *a) {
    // Encontrar o valor máximo em a
    int size = sizeof(a);
    int maxA = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > maxA) {
            maxA = a[i];
        }
    }
    
    // Passo 1: Contagem das ocorrências dos elementos
    int *c = (int*)malloc((maxA + 1) * sizeof(int));
    for (int i = 0; i <= maxA; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        c[a[i]]++;
    }

    // Passo 2: Determinação das posições finais
    for (int i = 1; i <= maxA; i++) {
        c[i] += c[i - 1];
    }

    // Passo 3: Construção do array ordenado
    int *b = (int*)malloc(size * sizeof(int));
    for (int i = size - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    free(c);
    return b;
}

// Função de ordenação Pigeonhole Sort
int* ordenacaoPigeonhole(int *a) {
    // Encontrar o valor mínimo e máximo em a
    int size = sizeof(a);
    int minimum = a[0];
    int maximum = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] < minimum) {
            minimum = a[i];
        }
        if (a[i] > maximum) {
            maximum = a[i];
        }
    }

    // Determinar o tamanho do vetor
    int hole_size = maximum - minimum + 1;

    // Criar os Pigeonholes
    int *c = (int*)malloc(hole_size * sizeof(int));
    for (int i = 0; i < hole_size; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        c[a[i] - minimum]++;
    }

    // Reconstruir o array ordenado
    int index = 0;
    for (int j = 0; j < hole_size; j++) {
        while (c[j] > 0) {
            a[index++] = j + minimum;
            c[j]--;
        }
    }

    free(c);
    return a;
}

int* ordenar(int *a) {
    clock_t start, end;
    double tempo_coun = 0.0, tempo_hole = 0.0;
    const int numIteracoes = 10;

    // Medição do tempo para ordenacaoCounting
    for (int i = 0; i < numIteracoes; i++) {
        start = clock();
        ordenacaoCounting(a);
        end = clock();
        tempo_coun += ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    tempo_coun /= numIteracoes;
    tempo_coun *= 1e9; // Convertendo para nanossegundos

    // Medição do tempo para ordenacaoPigeonhole
    for (int i = 0; i < numIteracoes; i++) {
        start = clock();
        ordenacaoPigeonhole(a);
        end = clock();
        tempo_hole += ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    tempo_hole /= numIteracoes;
    tempo_hole *= 1e9; // Convertendo para nanossegundos

    // Criando um array para armazenar os tempos em formato inteiro
    int *resultados = (int *)malloc(2 * sizeof(int));
    resultados[0] = (int)tempo_coun;
    resultados[1] = (int)tempo_hole;

    return resultados;
}

