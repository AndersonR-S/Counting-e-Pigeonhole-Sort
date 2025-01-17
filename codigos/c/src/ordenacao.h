#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// Função de ordenação Counting Sort
int* ordenacaoCounting(int *a, int size);

// Função de ordenação Pigeonhole Sort
int* ordenacaoPigeonhole(int *a, int size);

// Função para medir tempos em nanossegundos
int* tempo(int *a, int size);

#endif