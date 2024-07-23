#include "ordenacao.hpp"
#include "csv.hpp"
#include <iostream>
#include <vector>

int main() {
    CSV csv; 
    Ordenacao ordenacao; 

    std::vector<int>input = csv.readCSV("../../dataset/input.csv");
    
    // Ordenação desordenada 
    std::vector<int> tempo_de = ordenacao.tempo(input);
    // O input ja fica ordenado quando passa para pegar o tempo desordenado
    // Ordenação dos números ordenados
    std::vector<int> tempo_or = ordenacao.tempo(input);

    // Criação de um vetor para armazenar os tempos a serem escritos no CSV
    std::vector<int> tempo;
    tempo.push_back(tempo_de[0]);
    tempo.push_back(tempo_de[1]);
    tempo.push_back(tempo_or[0]);
    tempo.push_back(tempo_or[1]);

    std::string name_output = csv.readNameOutput("../../dataset/valores.csv");
    csv.writeCSV(name_output, tempo);

    return 0;
}
