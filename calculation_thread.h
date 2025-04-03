#ifndef CALCULATION_THREAD_H
#define CALCULATION_THREAD_H

#include <pthread.h>
#include <stdlib.h>
#include "calculate.h"

typedef struct calculation{
    float a,b;
    char operation;
}Calculation;

void* calculate_thread(void *arg);

#endif
