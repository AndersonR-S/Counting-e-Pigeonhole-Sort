#include "ordenacao.hpp"

Ordenacao::Ordenacao(){
}

std::vector<int> Ordenacao::ordenacaoCounting(std::vector<int>& a) {
    int maxA = 0;
    int size = a.size();
    
    for (int i = 0; i < size; i++) {
        if (a[i] > maxA) {
            maxA = a[i];
        }
    }
    
    std::vector<int> c(maxA + 1, 0); 
    for (int i = 0; i < size; i++) {
        c[a[i]]++;
    }

    for (int i = 1; i <= maxA; i++) {
        c[i] += c[i - 1];
    }

    std::vector<int> b(size);
    for (int i = size - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    return b;
}

void Ordenacao::ordenacaoPigeonhole(std::vector<int>& a) {
    int size = a.size();
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

    std::vector<int> c(hole_size, 0);
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
}

std::vector<int> Ordenacao::tempo(std::vector<int>& a) {
    clock_t start, end;
    const int num_iteracoes = 10;

    // Medição do tempo para ordenacaoCounting
    double tempo_ting = 0.0;
    for (int i = 0; i < num_iteracoes; i++) {
        start = clock();
        ordenacaoCounting(a);
        end = clock();
        tempo_ting += ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    tempo_ting /= num_iteracoes;
    tempo_ting *= 1e9; 

    // Medição do tempo para ordenacaoPigeonhole
    double tempo_hole = 0.0;
    for (int i = 0; i < num_iteracoes; i++) {
        start = clock();
        ordenacaoPigeonhole(a);
        end = clock();
        tempo_hole += ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    tempo_hole /= num_iteracoes;
    tempo_hole *= 1e9; 

    // Criando um vector para armazenar os tempos em formato inteiro
    std::vector<int> tempos(2);
    tempos[0] = (int)tempo_ting;
    tempos[1] = (int)tempo_hole;

    return tempos;
}
