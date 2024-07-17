#include "csv.h"

#define MAX_LINE_LENGTH 100

// Função para ler um arquivo CSV
int* readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s.\n", filename);
        exit(1);
    }

    // Variável para armazenar os números lidos do CSV
    int *numbers = NULL;
    int capacity = 10; // Capacidade inicial do array
    int count = 0;     // Contador de elementos lidos

    numbers = (int *)malloc(capacity * sizeof(int));
    if (numbers == NULL) {
        fclose(file);
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Ignorar a primeira linha (header) do CSV
        if (count == 0) {
            count++;
            continue;
        }

        // Extrair o número da linha
        int number;
        if (sscanf(line, "%d", &number) != 1) {
            fprintf(stderr, "Erro ao ler número do arquivo CSV.\n");
            free(numbers);
            fclose(file);
            exit(1);
        }

        // Armazenar o número no array
        numbers[count - 1] = number;
        count++;

        // Aumentar a capacidade do array, se necessário
        if (count > capacity) {
            capacity *= 2;
            numbers = (int *)realloc(numbers, capacity * sizeof(int));
            if (numbers == NULL) {
                fclose(file);
                fprintf(stderr, "Erro de alocação de memória.\n");
                exit(1);
            }
        }
    }

    fclose(file);
    return numbers;
}

// Função para escrever um arquivo CSV
void writeCSV(const char *filename, int *newData) {

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s para leitura.\n", filename);
        exit(1);
    }
    // Lê o conteúdo atual do arquivo CSV
    char lines[MAX_LINE_LENGTH][MAX_LINE_LENGTH];
    int lineCount = 0;

    // Ler e armazenar as linhas restantes do arquivo
    while (fgets(lines[lineCount], MAX_LINE_LENGTH, file)) {
        //printf("%s\n",lines[lineCount]);
        lineCount++;
    }

    fclose(file);
    
    // Escrever de volta no arquivo CSV
    file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Erro ao abrir o arquivo %s para escrita.\n", filename);
        exit(1);
    }

    fputs(lines[0],file);

    int contador;
    for (int i = 0; i < lineCount-1; i++) {

        contador= 0;
        for(int j = 0; j < 100; j++){
            if(lines[i+1][j]==',' && contador==2){

                fprintf(file, ",%d", newData[i]);
                fprintf(file, "%s", ",,\n");
                break;
            }
            else if(lines[i+1][j]==','){
                contador++;
            }
            fprintf(file, "%c", lines[i+1][j]);
        }
    }

    fclose(file);
}
