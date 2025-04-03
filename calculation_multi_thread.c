#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include "calculation_thread.h"

#define MAX_CALCULATIONS 3

int main(){
    clock_t start_time = clock();

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
        pthread_create(&threads[i], NULL, calculate_thread, &calculations[i]);
    }

    for(int i = 0; i < MAX_CALCULATIONS; i++){
        pthread_join(threads[i], (void **)&results[i]);
    }

    float final_result = *results[0] + *results[1] * *results[2];
    printf("Result: %.2f\n", final_result); 

    clock_t finish_time = clock();
    double execution_time = (double)(finish_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %.6lf seconds\n", execution_time);
    
    return 0;
}