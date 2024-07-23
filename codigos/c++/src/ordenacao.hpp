#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP

#include <vector>
#include <ctime>
#include <string>

class Ordenacao {
public:
    Ordenacao();
    // Função de ordenação Counting Sort
    std::vector<int> ordenacaoCounting(std::vector<int>& a);

    // Função de ordenação Pigeonhole Sort
    void ordenacaoPigeonhole(std::vector<int>& a);

    // Função para ordenar e medir tempos em nanossegundos
    std::vector<int> tempo(std::vector<int>& a);

};

#endif
