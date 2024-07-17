#include "csv.hpp"

CSV::CSV(){}

std::vector<int> CSV::readCSV(const std::string &filename) {
    std::cout<<filename;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
        exit(1);
    }

    std::vector<int> numbers;
    std::string line;
    bool firstLine = true;

    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue; // Ignora o cabeçalho
        }

        int number;
        std::stringstream ss(line);
        if (!(ss >> number)) {
            std::cerr << "Erro ao ler número do arquivo CSV." << std::endl;
            file.close();
            exit(1);
        }

        numbers.push_back(number);
    }

    file.close();
    return numbers;
}


void CSV::writeCSV(const std::string &filename, const std::vector<int>& newData) {
    // Exibe os novos dados no console
    std::cout << "Novos dados: ";
    for (auto num : newData) {
        std::cout << num << ", ";
    }
    std::cout << "\n--------------------------\n";

    // Abre o arquivo CSV para leitura
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << filename << " para leitura.\n";
        return;
    }

    // Armazena as linhas do arquivo CSV em um vetor de strings
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();

    // Abre o arquivo CSV para escrita (sobrescreve o arquivo existente)
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << filename << " para escrita.\n";
        return;
    }

    // Escreve o cabeçalho do arquivo CSV (primeira linha)
    if (!lines.empty()) {
        outputFile << lines[0] << "\n";
    }

    // Escreve os dados atualizados no arquivo CSV
    int contador;
    for (size_t i = 1; i < lines.size(); ++i) {
        contador = 0;
        for (size_t j = 0; j < lines[i].size(); ++j) {
            if(contador > 3 && contador < 5 && lines[i][j] != ','){
                continue;
            }
            else if (lines[i][j] == ',' && contador == 3) {
                outputFile << "," << newData[i - 1];
                contador++;
                continue;
            } else if (lines[i][j] == ',') {
                contador++;
            }
            outputFile << lines[i][j];
        }
        outputFile << std::endl;
    }

    outputFile.close();
}
