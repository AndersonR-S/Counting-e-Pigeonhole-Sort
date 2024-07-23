#ifndef CSV_H
#define CSV_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int* readCSV(const char *filename, int *size);

void writeCSV(const char *filename, int data[]);

char* readNameOutput(const char* filename);
#endif