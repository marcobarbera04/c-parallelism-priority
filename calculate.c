#include "calculate.h"

float calculate(float a, float b, char operation){
    if(operation == '+'){
        return a + b;
    }
    else if(operation == '-'){
        return a - b;
    }
    else if(operation == '*'){
        return a * b;
    }
    else if(operation == '/'){
        return a / b;
    }
    else{
        return 0;
    }
}