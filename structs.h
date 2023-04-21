typedef enum{
    User_Win,
    User_Loose, 
    User_Tie,
    No_Result
} Game_Result; 

typedef struct{
    char date[26];
    Game_Result result; 
} CurrentGame; 

typedef struct{
    CurrentGame *currentGame;
    int numberOfGames; 
}GameRecord; 

GameRecord gameRecord;  