#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "calculateFunctions.h"
#include "safeinput.h"
#include "empty_stdin.h"
#define RECTANGEL 1
#define PARALLELOGRAM 2
#define TRIANGEL 3
#define CIRCLE 4
#define PI 3.141593

int shapeMenu(){
    char shapeInput[20];
    while(true){  
        printf("\nOn which shape do you want to calculate the area?\n"
                    "* Rectangle\n"
                    "* Parallelogram\n"
                    "* Triangle\n"
                    "* Circle\n"
                    "* Exit\n");
        if(fgets(shapeInput, 20, stdin) != NULL){ 
            *shapeInput= upperCase(shapeInput);                                                     
            if(strcmp(shapeInput, "RECTANGLE") == 0){
                return 1;
            }else if (strcmp(shapeInput, "PARALLELOGRAM") == 0){
                return 2;
            }else if(strcmp(shapeInput, "TRIANGLE") == 0){
                return 3; 
            }else if (strcmp(shapeInput, "CIRCLE") == 0){
                return 4;
            }else if (strcmp(shapeInput, "EXIT") == 0){
                return 5;
            }else{
                printf("invalid input."); 
            }
        }else 
            printf("invalid input.");
    }    
}

void printCalculations(const float base, const float height, const float lenght, const float area, const float circumference, int shape){
    if(shape == RECTANGEL)
        printf("\nThe area of a rectangle with a base of %.2fcm and a height of %.2fcm is %.2fcm2\n", base, height, area);
    if (shape == PARALLELOGRAM)
        printf("\nThe area of a parallelogram with a base of %.2fcm and a height of %.2fcm is %.2fcm2\n", base, height, area);
    if(shape == TRIANGEL)
        printf("\nThe area of a triangel with a base of %.2fcm, a height of %.2fcm and a lenght of %.2fcm is %.2fcm2\n", base, height, lenght, area);
    if(shape == CIRCLE)
        printf("\nThe area of a circle with a radius of %.2fcm is %.2fcm\n", base, area);
    
    printf("and the circumference  is %.2fcm\n\n", circumference);
    sleep(1); 
    return; 
}

void calculateShape(const int base, const int height, const int lenght, int shape){
    float area, circumference;
    if((shape == RECTANGEL || shape == PARALLELOGRAM)){
        area = base * height; 
        circumference = (2 * base) + (2 * height); 
        printCalculations(base, height, 0,  area, circumference, shape); 
        return; 
    }
    if(shape == TRIANGEL){
        area = base * height /2; 
        circumference = base + height + lenght; 
        printCalculations(base, height, lenght, area, circumference, TRIANGEL); 
        return;
    }
    if(shape == CIRCLE){
        area = PI*(base * base); 
        circumference = (2 * PI) * base; 
        printCalculations(base, 0 , 0, area, circumference, CIRCLE); 
        return; 
    }
}

void shapeInput(int shape){
    float base, height, lenght;
    if(shape == RECTANGEL || shape == PARALLELOGRAM){
        while(true){
            printf("Input the mesurements in cm of base and height:\n"); 
            if((scanf("%f", &base)) && (scanf("%f", &height)) && base > 0 && height > 0 ){
                calculateShape(base, height, 0, shape); 
                empty_stdin();
                return;
            }else{
                printf("input must be two positive numbers.\n");
                empty_stdin();
            }
        }
    }else if(shape == TRIANGEL){
        while(true){
            printf("Input the mesurements in cm of base, height and lenght:\n"); 
            if((scanf("%f", &base)) && (scanf("%f", &height)) && (scanf("%f", &lenght))
                && base > 0 && height > 0 && lenght > 0){
                calculateShape(base, height, lenght, TRIANGEL); 
                empty_stdin();
                return;
            }else{
                printf("input must be three positive numbers.");
                empty_stdin();
            }
        }
    }else{
        while(true){
            printf("\nInput the radius in cm:");
            if(scanf("%f",&base) && base > 0){
                calculateShape(base, 0, 0, CIRCLE); 
                empty_stdin(); 
                return; 
            }else{
                printf("input must be a positive number.");
                empty_stdin();
            }
        }
    }
}

bool chooseShape(){
    while(true){
        switch (shapeMenu()){
        case 1:
            shapeInput(RECTANGEL);
            if(playAgain())
                break;
            else
                return false; 
        case 2:
            shapeInput(PARALLELOGRAM);
            if(playAgain())
                break;
            else
                return false; 
        case 3: 
            shapeInput(TRIANGEL);
            if(playAgain())
                break;
            else
                return false; 
        case 4:
            shapeInput(CIRCLE);
            if(playAgain())
                break;
            else
                return false; 
        case 5:
            return false;
        default:
            printf("Invalid input\nPress enter to continue");
            empty_stdin(); 
            break;
        }
    }
}

