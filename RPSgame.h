#ifndef __RPS_GAME_H_
#define __RPS_GAME_H_
#include "structs.h"

void RPSGame(); 
Game_Result decideWinner(const char *userChoice, const int computerChoice);

#endif
