#include "ordenacao.hpp"

Ordenacao::Ordenacao(){

}
// Função de ordenação Counting Sort
std::vector<int> Ordenacao::ordenacaoCounting(std::vector<int>& a) {
    // Encontrar o valor máximo em a
    int maxA = 0;
    int size = a.size();
    
    for (int i = 0; i < size; i++) {
        if (a[i] > maxA) {
            maxA = a[i];
        }
    }
    
    // Passo 1: Contagem das ocorrências dos elementos
    std::vector<int> c(maxA + 1, 0); // Inicializa com 0
    for (int i = 0; i < size; i++) {
        c[a[i]]++;
    }

    // Passo 2: Determinação das posições finais
    for (int i = 1; i <= maxA; i++) {
        c[i] += c[i - 1];
    }

    // Passo 3: Construção do array ordenado
    std::vector<int> b(size);
    for (int i = size - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    return b;
}

// Função de ordenação Pigeonhole Sort
void Ordenacao::ordenacaoPigeonhole(std::vector<int>& a) {
    // Encontrar o valor mínimo e máximo em a
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

    // Determinar o tamanho do vetor de pigeonholes
    int hole_size = maximum - minimum + 1;

    // Criar os Pigeonholes
    std::vector<int> c(hole_size, 0);
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
}

// Função para ordenar e medir tempos em nanossegundos
std::vector<int> Ordenacao::ordenar(std::vector<int>& a) {

    // Medição do tempo para ordenacaoCounting
    clock_t start, end;
    double tempo_coun = 0.0;
    const int numIteracoes = 10;

    for (int i = 0; i < numIteracoes; i++) {
        start = clock();
        ordenacaoCounting(a);
        end = clock();
        tempo_coun += ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    tempo_coun /= numIteracoes;
    tempo_coun *= 1e9; // Convertendo para nanossegundos

    // Medição do tempo para ordenacaoPigeonhole
    double tempo_hole = 0.0;
    for (int i = 0; i < numIteracoes; i++) {
        start = clock();
        ordenacaoPigeonhole(a);
        end = clock();
        tempo_hole += ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    tempo_hole /= numIteracoes;
    tempo_hole *= 1e9; // Convertendo para nanossegundos

    // Criando um vector para armazenar os tempos em formato inteiro
    std::vector<int> tempos(2);
    tempos[0] = (int)tempo_coun;
    tempos[1] = (int)tempo_hole;

    return tempos;
}
