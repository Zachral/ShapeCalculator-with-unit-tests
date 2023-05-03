#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "supportFunctions.h"

float calculate(float operand1, float operand2, char op){
    float result; 
    int num1, num2;
    switch (op){
    case '+':
        return result = operand1 + operand2;  
        break;
    case '-': 
        return result = operand1 - operand2; 
        break;
    case '*':
        return result = operand1 * operand2;
        break;
    case '/':
        return result = operand1 / operand2; 
        break;
    case '%': 
        num1 = (int)operand1;
        num2 = (int)operand2;
        return result = num1 % num2;
        break;
    default:
        break;
    }
return 0;
}

void printResult(const float operand1, const float operand2, const char op, const float result){
    printf("%.2f %c %.2f = %.2f", operand1, op, operand2, result);
    return; 
}


int calculatorInput(){
    char op; 
    float operand1, operand2, result; 
    while(true){
        printf("\nOperators: +, -, *, /, %%");
        GetInputChar("\nChoose which operator you want to use: ", &op); 
        if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%'){
            printf("Invalid input\nPress enter to continue");
            empty_stdin(); 
        }else{
            while(true){
                printf("\nInput the two operands: \n");
                if((scanf("%f", &operand1)) && (scanf("%f", &operand2))){
                    result = calculate(operand1, operand2, op); 
                    printResult(operand1, operand2, op, result);
                    empty_stdin(); 
                    if(playAgain())
                        break; 
                    else
                        return 0; 
                }else{
                    printf("input must be two numbers.\n");
                    empty_stdin();
                } 
            }
        }
    }
return 0;
}

