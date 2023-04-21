#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>  
#include <unistd.h>
#include "structs.h"
#include "safeinput.h"
#include "empty_stdin.h"
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int printToFile(Game_Result result){
    char currentDate[26];
    time_t timer;
    struct tm* date_info ={0}; 
    timer = time(NULL);
    date_info = localtime(&timer);  
    strftime(currentDate,26, "%Y-%m-%d", date_info);

    FILE *file; 
    file = fopen("gameRecord.dat", "ab"); 
    if (file == NULL) {
            printf("Something went wrong when opening the file");
            return 1;
    }
    gameRecord.numberOfGames++;

    if(gameRecord.numberOfGames == 1)
        gameRecord.currentGame = (CurrentGame *)malloc(1 * sizeof(CurrentGame)); 
    else 
        gameRecord.currentGame = (CurrentGame *)realloc(gameRecord.currentGame, gameRecord.numberOfGames * sizeof(CurrentGame));

    strcpy(gameRecord.currentGame[gameRecord.numberOfGames -1].date, currentDate);  
    gameRecord.currentGame->result = result; 
    fwrite(&gameRecord.currentGame[gameRecord.numberOfGames -1], sizeof(CurrentGame), 1, file);  
    printf("%d", gameRecord.numberOfGames);     
    fclose(file); 
    return 0;
}

float calculateWinRatio(GameRecord *gameRecord){
    int counter = 0;
    int totalWins = 0;
    float totalWinPercentage; 
    FILE *file; 
    file = fopen("gameRecord.dat", "rb"); 
    if (file == NULL) {
            printf("Something went wrong when opening the file");
            return 1;
    }
    while(!feof(file)){
        if(counter == 0)
            gameRecord->currentGame = (CurrentGame *)malloc(1 * sizeof(CurrentGame)); 
        else 
            gameRecord->currentGame = (CurrentGame *)realloc(gameRecord->currentGame, (counter + 1) * sizeof(CurrentGame));
        fread(&gameRecord->currentGame[counter], sizeof(gameRecord->currentGame[0]), 1, file); 
       // if(&gameRecord->currentGame[counter].result == User_Win)
        //    totalWins++; 
        counter++;
    }
    return totalWinPercentage = (totalWins/counter) * 100; 
}

char upperCase(char *string){
    int i; 
    for(i = 0; string[i] != '\0'; i++){
        string[i] = toupper(string[i]); 
    }
    if (i >= 2){
        string[i-1] = '\0'; 
        return *string; 
    }else
        return *string; 
}

int randomChoice(){
    int computerChoice;
    srand(time(NULL));
    computerChoice = (rand() % 3) + 1;
    return computerChoice; 
}

void printChoices(char *userChoice, int computerChoice, Game_Result result){
    if (computerChoice == ROCK)
        printf("\nYou chose %s\nThe computer chose ROCK\n", userChoice);
    if (computerChoice == PAPER)
        printf("\nYou chose %s\nThe computer chose PAPER\n", userChoice); 
    if (computerChoice == SCISSORS)
        printf("\nYou chose %s\nThe computer chose SCISSORS\n", userChoice);
    
    if(result == User_Win){
        printf("You Win!");
        return;
    }
    if(result == User_Loose){
        printf("You Loose!");
        return;
    }
    if(result == User_Tie){
        printf("It's a tie!");
        return; 
    }
    return; 
}

Game_Result decideWinner(char *userChoice, int computerChoice){
    if((strcmp(userChoice, "ROCK") == 0 && computerChoice == SCISSORS) 
        || (strcmp(userChoice, "PAPER") == 0 && computerChoice == ROCK) 
        || (strcmp(userChoice, "SCISSORS") == 0 && computerChoice== PAPER))
            return User_Win; 
    if((strcmp(userChoice, "ROCK") == 0 && computerChoice == PAPER) 
        || (strcmp(userChoice, "PAPER") == 0 && computerChoice == SCISSORS) 
        || (strcmp(userChoice, "SCISSORS") == 0 && computerChoice== ROCK))
            return User_Loose;
    if ((strcmp(userChoice, "ROCK") == 0 && computerChoice == ROCK) 
        || (strcmp(userChoice, "PAPER") == 0 && computerChoice == PAPER) 
        || (strcmp(userChoice, "SCISSORS") == 0 && computerChoice== SCISSORS))
            return User_Tie; 
    return No_Result; 
}

bool playAgain(){
    while(true){
        char playAgain[5]; 
        printf("\nDo you want to go again? Y/N ");
        fgets(playAgain, 5, stdin); 
        *playAgain = upperCase(playAgain);
        if(strcmp(playAgain, "Y") == 0){
            return true;
        }else if (strcmp(playAgain, "N") == 0){
            return false;  
        }else{
            printf("Invalid input\n");
        }
    }
}

void RPSGame(){
    char userChoice[10];
    int computerChoice; 
    printf("\nWelcome to the Rock, paper, scissors game!");
    while(true){
        printf("\nRock, paper or scissors?\n"); 
        fgets(userChoice, 10, stdin);   
        *userChoice = upperCase(userChoice); 
        if((strcmp(userChoice, "ROCK") == 0 || strcmp(userChoice, "PAPER") == 0 || strcmp(userChoice, "SCISSORS") == 0)){
            computerChoice = randomChoice(); 
            Game_Result result = decideWinner(userChoice, computerChoice);
            if(result != No_Result){
                printChoices(userChoice, computerChoice, result); 
                printToFile(result);
            }else{
                printf("Something went wrong, could not decide a winner!");
            }
            if(playAgain())
                continue;
            else{
                printf("You have won %.0f%% of the games", calculateWinRatio(&gameRecord)); 
                return;
            } 
        }else{
            printf("Invalid input\n");
        }
    }
}