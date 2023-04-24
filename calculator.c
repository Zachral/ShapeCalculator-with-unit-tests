#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "supportFunctions.h"

float calculateAndPrint(float operand1, float operand2, char op){
    float result; 
    int num1, num2;
    switch (op){
    case '+':
        result = operand1 + operand2; 
        printf("%.2f + %.2f = %.2f\n", operand1, operand2, result ); 
        sleep(1); 
        return result; 
        break;
    case '-':
        result = operand1 - operand2; 
        printf("%.2f - %.2f = %.2f\n", operand1, operand2, result ); 
        sleep(1); 
        return result; 
        break;
    case '*':
        result = operand1 * operand2; 
        printf("%.2f * %.2f = %.2f\n", operand1, operand2, result ); 
        sleep(1); 
        return result; 
        break;
    case '/':
        result = operand1 / operand2; 
        printf("%.2f / %.2f = %.2f\n", operand1, operand2, result ); 
        sleep(1); 
        return result; 
        break;
    case '%': 
        num1 = (int)operand1;
        num2 = (int)operand2; 
        result = num1 % num2; 
        printf("%.2f %% %.2f = %.2f\n", operand1, operand2, result ); 
        sleep(1); 
        return result; 
        break;
    default:
        break;
    }
return 0;
}

int calculatorInput(){
    char op; 
    float operand1, operand2; 
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
                    calculateAndPrint(operand1, operand2, op); 
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

