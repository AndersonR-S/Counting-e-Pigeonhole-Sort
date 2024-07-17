#include "ordenacao.hpp"
#include "csv.hpp"
#include <iostream>
#include <vector>

int main() {
    CSV csv; // Instância da classe CSV para ler e escrever arquivos CSV
    Ordenacao ordenacao; // Instância da classe Ordenacao para realizar as ordenações

    // Leitura do arquivo CSV de entrada
    std::vector<int>input = csv.readCSV("../../dataset/input.csv");
    
    // Ordenação desordenada usando a função ordenar da classe Ordenacao
    std::vector<int> tempo_de = ordenacao.ordenar(input);

    // O input ja fica ordenado quando passa para pegar o tempo desordenado
    
    // Ordenação dos números ordenados
    std::vector<int> tempo_or = ordenacao.ordenar(input);

    // Criação de um vetor para armazenar os tempos a serem escritos no CSV
    std::vector<int> tempo;
    tempo.push_back(tempo_de[0]);
    tempo.push_back(tempo_de[1]);
    tempo.push_back(tempo_or[0]);
    tempo.push_back(tempo_or[1]);

    // Escrita dos tempos no arquivo CSV de saída
    csv.writeCSV("../../dataget/output.csv", tempo);

    return 0;
}
