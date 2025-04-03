#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include "calculation_thread.h"

#define MAX_CALCULATIONS 3

int main(){
    clock_t start_time = clock();

    Calculation calculations[MAX_CALCULATIONS];
    pid_t pids[MAX_CALCULATIONS];
    int pipefds[MAX_CALCULATIONS][2];

    calculations[0].a = 2;
    calculations[0].b = 6;
    calculations[0].operation = '*';

    calculations[1].a = 1;
    calculations[1].b = 4;
    calculations[1].operation = '+';

    calculations[2].a = 5;
    calculations[2].b = 2;
    calculations[2].operation = '-';

    // creating pipes and child processes
    for(int i = 0; i < MAX_CALCULATIONS; i++){
        if(pipe(pipefds[i]) == -1){
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        if((pids[i] = fork()) < 0){
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if(pids[i] == 0){
            // child process
            close(pipefds[i][0]);   // close reading pipe
            float a = calculations[i].a;
            float b = calculations[i].b;
            char operation = calculations[i].operation;
            float result = calculate(a, b, operation);
            
            // write result in the pipe
            write(pipefds[i][1], &result, sizeof(result));
            close(pipefds[i][1]);
            
            exit(0);
        }
        else{
            // parent process
            close(pipefds[i][1]);   // close writing pipe
        }
    }

    float results[MAX_CALCULATIONS];
    // parent process wait for child processes
    for(int i = 0; i < MAX_CALCULATIONS; i++){
        read(pipefds[i][0], &results[i], sizeof(results[i]));
        close(pipefds[i][0]);   // close reading pipe
        waitpid(pids[i], NULL, 0);
    }

    // final calculation
    float final_result = results[0] + results[1] * results[2];
    printf("Result: %.2f\n", final_result);

    clock_t finish_time = clock();
    double execution_time = (double)(finish_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %.12lf\n", execution_time);

    return 0;
}