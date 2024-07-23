#include "ordenacao.h"

int* ordenacaoCounting(int *a, int size) {
    int maxA = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > maxA) {
            maxA = a[i];
        }
    }
    
    int *c = (int*)malloc((maxA + 1) * sizeof(int));
    if (c == NULL) {
        fprintf(stderr, "Erro ao alocar memória para c\n");
        return NULL;
    }
    for (int i = 0; i <= maxA; i++) {
        c[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        c[a[i]]++;
    }

    for (int i = 1; i <= maxA; i++) {
        c[i] += c[i - 1];
    }

    int *b = (int*)malloc(size * sizeof(int));
    if (b == NULL) {
        fprintf(stderr, "Erro ao alocar memória para b\n");
        free(c);
        return NULL;
    }
    
    for (int i = size - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    free(c);
    return b;
}

int* ordenacaoPigeonhole(int *a,int size) {
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

    int hole_size = maximum - minimum + 1;

    int *c = (int*)malloc(hole_size * sizeof(int));
    for (int i = 0; i < hole_size; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        c[a[i] - minimum]++;
    }

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

int* tempo(int *a, int size) {
    clock_t start, end;
    double tempo_coun = 0.0, tempo_hole = 0.0;
    const int num_iteracoes = 10;

    // Medição do tempo para ordenacaoCounting
    for (int i = 0; i < num_iteracoes; i++) {
        start = clock();
        ordenacaoCounting(a,size);
        end = clock();
        tempo_coun += ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    tempo_coun /= num_iteracoes;
    tempo_coun *= 1e9; 

    // Medição do tempo para ordenacaoPigeonhole
    for (int i = 0; i < num_iteracoes; i++) {
        start = clock();
        ordenacaoPigeonhole(a,size);
        end = clock();
        tempo_hole += ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    tempo_hole /= num_iteracoes;
    tempo_hole *= 1e9; // Convertendo para nanossegundos

    // Criando um array para armazenar os tempos em formato inteiro
    int *resultados = (int *)malloc(2 * sizeof(int));
    resultados[0] = (int)tempo_coun;
    resultados[1] = (int)tempo_hole;

    return resultados;
}

