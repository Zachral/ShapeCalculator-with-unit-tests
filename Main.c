#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "calculator.h"
#include "calculateFunctions.h"
#include "supportFunctions.h"

int main(){
    while(true){
        int menuChoice; 
        GetInputInt("\nMenu:\n1. Calculate the area of a shape\n2. Open calculator\n3. Play rock, paper, scissors\n4. Exit\nChoice: ", &menuChoice);

        switch (menuChoice){
        case 1:
            chooseShape();  
            break;
        case 2: 
            calculatorInput();
            break;
        case 3:
            RPSGame(); 
            break;
        case 4: 
            return false;
            break; 
        default:
            printf("Invalid input\nPress enter to continue");
            empty_stdin(); 
            break;
        }
    }


return 0;
}
