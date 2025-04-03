#include <pthread.h>
#include <stdio.h>
#include "calculate.h"

#define MAX_CALCULATIONS 3

int main(){
    pthread_t threads[MAX_CALCULATIONS];
    Calculation calculations[MAX_CALCULATIONS];
    float *results[MAX_CALCULATIONS];

    threads[0] = 0;
    calculations[0].a = 2;
    calculations[0].b = 6;
    calculations[0].operation = '*';

    threads[1] = 1;
    calculations[1].a = 1;
    calculations[1].b = 4;
    calculations[1].operation = '+';

    threads[2] = 2;
    calculations[2].a = 5;
    calculations[2].b = 2;
    calculations[2].operation = '-';

    for(int i = 0; i < MAX_CALCULATIONS; i++){
        pthread_create(&threads[i], NULL, calculate, &calculations[i]);
    }

    for(int i = 0; i < MAX_CALCULATIONS; i++){
        pthread_join(threads[i], (void **)&results[i]);
    }

    float final_result = *results[0] + *results[1] * *results[2];
    printf("Result: %.2f\n", final_result); 
}