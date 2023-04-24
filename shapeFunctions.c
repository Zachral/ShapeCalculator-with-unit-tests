#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "calculateFunctions.h"
#include "supportFunctions.h"
#define RECTANGEL 1
#define PARALLELOGRAM 2
#define TRIANGEL 3
#define CIRCLE 4
#define PI 3.141593

int shapeMenu(){
    char shapeInput[20];
    while(true){  
        printf("\nOn which shape do you want to calculate the area and circumference?\n"
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
                printf("Invalid input.\n"); 
            }
        }else 
            printf("Invalid input.\n");
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
    
    printf("The circumference is %.2fcm\n\n", circumference);
    sleep(1); 
    return; 
}

float calculateCircumference(const int base, const int height, const int lenght, int shape){
    float circumference;
    if((shape == RECTANGEL || shape == PARALLELOGRAM)) return circumference = (2 * base) + (2 * height); 
    if(shape == TRIANGEL) return circumference = base + height + lenght; 
    if(shape == CIRCLE) return  circumference = (2 * PI) * base;   
return 1; 
}

float calculateArea(const int base, const int height, int shape){
    float area;
    if((shape == RECTANGEL || shape == PARALLELOGRAM)) return area = base * height; 
    if(shape == TRIANGEL) return area = base * height /2; 
    if(shape == CIRCLE) return area = PI*(base * base); 
return 1; 
}

void shapeInput(int shape){
    float base, height, lenght, area, circumference; 
    if(shape == RECTANGEL || shape == PARALLELOGRAM){
        while(true){
            printf("Input the mesurements in cm of base and height:\n"); 
            if((scanf("%.2f", &base)) && (scanf("%.2f", &height)) && base > 0 && height > 0 ){
                area = calculateArea(base, height, shape); 
                circumference = calculateCircumference(base, height, 0, shape); 
                printCalculations(base, height, 0,  area, circumference, shape); 
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
            if((scanf("%.2f", &base)) && (scanf("%.2f", &height)) && (scanf("%.2f", &lenght))
                && base > 0 && height > 0 && lenght > 0){
                area = calculateArea(base, height, TRIANGEL); 
                circumference = calculateCircumference(base, height, lenght, TRIANGEL);
                printCalculations(base, height, lenght, area, circumference, TRIANGEL); 
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
            if(scanf("%.2f",&base) && base > 0){
                area = calculateArea(base, 0, CIRCLE); 
                circumference = calculateCircumference(base, 0, 0, CIRCLE); 
                printCalculations(base, 0 , 0, area, circumference, CIRCLE); 
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

