#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// Função de ordenação Counting Sort
int* ordenacaoCounting(int *a);

// Função de ordenação Pigeonhole Sort
int* ordenacaoPigeonhole(int *a);

// Função para ordenar e medir tempos em nanossegundos
int* ordenar(int *a);


#endif