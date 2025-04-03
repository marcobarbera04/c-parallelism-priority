#ifndef CALCULATE_H
#define CALCULATE_H

#include <pthread.h>
#include <stdlib.h>

typedef struct calculation{
    float a,b;
    char operation;
}Calculation;

void* calculate(void *arg);

#endif
