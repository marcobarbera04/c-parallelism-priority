#include "calculation_thread.h"

void* calculate_thread(void *arg){
    Calculation *calculation = (Calculation*)arg;
    float a = calculation->a;
    float b = calculation->b;
    char operation = calculation->operation;
    float *result = (float*)malloc(sizeof(float));

    *result = calculate(a, b, operation);
    pthread_exit(result);
}