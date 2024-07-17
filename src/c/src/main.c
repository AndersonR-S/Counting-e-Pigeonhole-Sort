#include "ordenacao.h"
#include "csv.h"


int main() {

    int *input = readCSV("../../dataset/input.csv");

    int *tempo_de = ordenar(input); //  Desordenado

    input = ordenacaoPigeonhole(input);

    int *tempo_or = ordenar(input);// Ordenado

    int *tempo = (int *)malloc(4 *sizeof(int *));
    for(int i = 0; i < 2; i++){
        tempo[i] = tempo_de[i];
        tempo[i] = tempo_de[i];

        tempo[i+2] = tempo_or[i];
        tempo[i+2] = tempo_or[i];
    }

    writeCSV("../../dataget/output.csv",tempo);

    free(input);

    return 0;
}