#ifndef CVS_HPP
#define C_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class CSV {
public:
    CSV();
    // Função para ler um arquivo CSV
    std::vector<int> readCSV(const std::string &filename);

    // Função para escrever um arquivo de saida
    void writeCSV(const std::string &filename, const std::vector<int> &newData);

    // Ler o caminho do arquivo de saida
    std::string readNameOutput(const std::string& filename);
};

#endif
