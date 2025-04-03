#include <stdio.h>
#include <time.h>
#include "calculate.h"

int main(){
    clock_t start_time = clock();

    float result0 = calculate(2, 6, '*');
    float result1 = calculate(1, 4, '+');
    float result2 = calculate(5, 2, '-');

    float y = result0 + result1 * result2;
    printf("Result: %.2f\n", y);

    clock_t finish_time = clock();
    double execution_time = (double)(finish_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time %.6lf seconds\n", execution_time);

    return 0;
}