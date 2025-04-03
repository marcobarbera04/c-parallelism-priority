#include "calculate.h"

void* calculate(void *arg){
    Calculation *calculation = (Calculation*)arg;
    float a = calculation->a;
    float b = calculation->b;
    float *result = (float*)malloc(sizeof(float));

    if(calculation->operation == '+'){
        *result = a + b;
        pthread_exit(result);
    }
    else if(calculation->operation == '-'){
        *result = a - b;
        pthread_exit(result);
    }
    else if(calculation->operation == '*'){
        *result = a * b;
        pthread_exit(result);
    }
    else if(calculation->operation == '/'){
        *result = a / b;
        pthread_exit(result);
    }
    else{
        *result = 0;
        pthread_exit(result);
    }
}