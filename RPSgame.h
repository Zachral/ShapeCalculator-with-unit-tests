#ifndef __RPS_GAME_H_
#define __RPS_GAME_H_
#include "structs.h"

void RPSGame(); 
Game_Result decideWinner(char *userChoice, int computerChoice);

#endif
