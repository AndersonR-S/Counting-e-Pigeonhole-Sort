#include "csv.h"

#define MAX_LINE_LENGTH 100

int* readCSV(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s.\n", filename);
        exit(1);
    }

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
        if (count == 0) {
            count++;
            continue;
        }

        int number;
        if (sscanf(line, "%d", &number) != 1) {
            fprintf(stderr, "Erro ao ler número do arquivo CSV.\n");
            free(numbers);
            fclose(file);
            exit(1);
        }

        numbers[count - 1] = number;
        count++;

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
    *size=count;
    fclose(file);
    return numbers;
}

void writeCSV(const char *filename, int *newData) {

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s para leitura.\n", filename);
        exit(1);
    }
    char lines[MAX_LINE_LENGTH][MAX_LINE_LENGTH];
    int lineCount = 0;

    // Ler e armazenar as linhas restantes do arquivo
    while (fgets(lines[lineCount], MAX_LINE_LENGTH, file)) {
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
    for (int i = 1; i < lineCount; ++i) {
            contador = 0;
            for (size_t j = 0; j < strlen(lines[i]); ++j) {
                if (contador > 2 && contador < 4 && lines[i][j] != ',') {
                    continue;
                } else if (lines[i][j] == ',' && contador == 2) {
                    fprintf(file, ",%d", newData[i - 1]);
                    contador++;
                    continue;
                } else if (lines[i][j] == ',') {
                    contador++;
                }
                fprintf(file, "%c", lines[i][j]);
            }
        }

    fclose(file);
}

char* readNameOutput(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char* name_output = (char*)malloc(MAX_LINE_LENGTH);
    strcpy(name_output, "../../dataget/output/");
    char line[MAX_LINE_LENGTH];
    int firstLine = 1;
    char* numbers[MAX_LINE_LENGTH];
    int numCount = 0;

    while (fgets(line, sizeof(line), file)) {

        line[strcspn(line, "\n")] = '\0';
        if (firstLine) {
            firstLine = 0;
            continue;
        }
        char* number = strtok(line, ",");
        if (number) {
            numbers[numCount] = strdup(number);
            numCount++;
        } else {
            fprintf(stderr, "Erro ao ler número do arquivo CSV.\n");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);

    if (numCount > 0) {
        strcat(name_output, numbers[0]);
        strcat(name_output, ":");
        strcat(name_output, numbers[1]);
        free(numbers[0]);
        free(numbers[1]);
    }

    strcat(name_output, ".csv");

    return name_output;
}