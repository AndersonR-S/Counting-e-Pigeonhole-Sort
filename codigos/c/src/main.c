#include "ordenacao.h"
#include "csv.h"


int main() {

    int size;
    int *input = readCSV("../../dataset/input.csv", &size);

    //  Desordenado
    int *tempo_de = tempo(input, size); 
    
    // Ordenado
    int *tempo_or = tempo(input, size);
    int *tempo_ = (int *)malloc(4 *sizeof(int *));
    
    for(int i = 0; i < 2; i++){
        tempo_[i] = tempo_de[i];
        tempo_[i+2] = tempo_or[i];

    }

    char *name_output = readNameOutput("../../dataset/valores.csv");
    writeCSV(name_output,tempo_);

    free(input);
    free(tempo_);
    free(tempo_de);
    free(tempo_or);
    free(name_output);

    return 0;
}