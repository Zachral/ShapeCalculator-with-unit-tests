#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "calculator.h"
#include "safeinput.h"
#include "empty_stdin.h"

void calculateAndPrint(float operand1, float operand2, char operator){
    float result; 
    int num1, num2;
    switch (operator){
    case '+':
        result = operand1 + operand2; 
        printf("%.2f + %.2f = %.2f\n", operand1, operand2, result ); 
        sleep(1); 
        break;
    case '-':
        result = operand1 - operand2; 
        printf("%.2f - %.2f = %.2f\n", operand1, operand2, result ); 
        sleep(1); 
        break;
    case '*':
        result = operand1 * operand2; 
        printf("%.2f * %.2f = %.2f\n", operand1, operand2, result ); 
        sleep(1); 
        break;
    case '/':
        result = operand1 / operand2; 
        printf("%.2f / %.2f = %.2f\n", operand1, operand2, result ); 
        sleep(1); 
        break;
    case '%': 
        num1 = (int)operand1;
        num2 = (int)operand2; 
        result = num1 % num2; 
        printf("%.2f %% %.2f = %.2f\n", operand1, operand2, result ); 
        sleep(1); 
        break;
    default:
        break;
    }
}

int calculatorInput(){
    char operator; 
    float operand1, operand2; 
    while(true){
        printf("\nOperators: +, -, *, /, %%");
        GetInputChar("\nChoose which operator you want to use: ", &operator); 
        if (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%'){
            printf("Invalid input\nPress enter to continue");
            empty_stdin(); 
        }else{
            while(true){
                printf("\nInput the two operands: \n");
                if((scanf("%f", &operand1)) && (scanf("%f", &operand2))){
                    calculateAndPrint(operand1, operand2, operator); 
                    empty_stdin(); 
                    if(playAgain())
                        continue;
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

