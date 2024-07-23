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
            continue;
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
    // Abre o arquivo CSV para leitura
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << filename << " para leitura.\n";
        return;
    }

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

std::string CSV::readNameOutput(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
        exit(1);
    }

    std::string name_output = "../../dataget/output/";
    std::string line;
    bool firstLine = true;
    std::vector<std::string> numbers;

    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }
        std::stringstream ss(line);
        std::string number;

        // Aqui, assumimos que o CSV tem apenas uma coluna por linha
        if (std::getline(ss, number, ',')) {
            numbers.push_back(number);
        } else {
            std::cerr << "Erro ao ler número do arquivo CSV." << std::endl;
            file.close();
            exit(1);
        }
    }

    file.close();

    if (!numbers.empty()) {

        name_output += numbers[0] + ":";
        name_output += numbers[1];  // Adiciona a última linha no final
    }

    return name_output + ".csv";
}