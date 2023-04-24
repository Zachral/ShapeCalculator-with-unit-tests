#include <gtest/gtest.h>
#define ROCK 1
#define PAPER 2
#define SCISSORS 3


extern "C" {
#include "RPSgame.h"
}

class RPSGameTest : public testing::Test {
protected:
	void SetUp() override {
	}
};

TEST_F(RPSGameTest,WhenPlayerChooseRockAndComputerChoosePaperShouldResultInUSER_LOOSE){
    //ARRANGE
    char userChoice[] = "ROCK";
    int computerChoice = PAPER;  

    //ACT
    Game_Result result = decideWinner(userChoice, computerChoice); 

    //ASSERT
    ASSERT_EQ(result, User_Loose);
}

TEST_F(RPSGameTest,WhenPlayerChooseRockAndComputerChooseRockShouldResultInUSER_TIE){
    //ARRANGE
    char userChoice[] = "ROCK";
    int computerChoice = ROCK;  

    //ACT
    Game_Result result = decideWinner(userChoice, computerChoice); 

    //ASSERT
    ASSERT_EQ(result, User_Tie);
}

TEST_F(RPSGameTest,WhenPlayerChooseRockAndComputerChooseScissorsShouldResultInUSER_WIN){
    //ARRANGE
    char userChoice[] = "ROCK";
    int computerChoice = SCISSORS;  

    //ACT
    Game_Result result = decideWinner(userChoice, computerChoice); 

    //ASSERT
    ASSERT_EQ(result, User_Win);
}

TEST_F(RPSGameTest,WhenPlayerChoosePaperAndComputerChooseScissorsShouldResultInUSER_LOOSE){
    //ARRANGE
    char userChoice[] = "PAPER";
    int computerChoice = SCISSORS;  

    //ACT
    Game_Result result = decideWinner(userChoice, computerChoice); 

    //ASSERT
    ASSERT_EQ(result, User_Loose);
}

TEST_F(RPSGameTest,WhenPlayerChoosePaperAndComputerChoosePaperShouldResultInUSER_TIE){
    //ARRANGE
    char userChoice[] = "PAPER";
    int computerChoice = PAPER;  

    //ACT
    Game_Result result = decideWinner(userChoice, computerChoice); 

    //ASSERT
    ASSERT_EQ(result, User_Tie);
}

TEST_F(RPSGameTest,WhenPlayerChoosePaperAndComputerChooseRockShouldResultInUSER_WIN){
    //ARRANGE
    char userChoice[] = "PAPER";
    int computerChoice = ROCK;  

    //ACT
    Game_Result result = decideWinner(userChoice, computerChoice); 

    //ASSERT
    ASSERT_EQ(result, User_Win);
}

TEST_F(RPSGameTest,WhenPlayerChooseScissorsAndComputerChooseRockShouldResultInUSER_LOOSE){
    //ARRANGE
    char userChoice[] = "SCISSORS";
    int computerChoice = ROCK;  

    //ACT
    Game_Result result = decideWinner(userChoice, computerChoice); 

    //ASSERT
    ASSERT_EQ(result, User_Loose);
}

TEST_F(RPSGameTest,WhenPlayerChooseScissorsAndComputerChooseScissorsShouldResultInUSER_LOOSE){
    //ARRANGE
    char userChoice[] = "SCISSORS";
    int computerChoice = SCISSORS;  

    //ACT
    Game_Result result = decideWinner(userChoice, computerChoice); 

    //ASSERT
    ASSERT_EQ(result, User_Tie);
}

TEST_F(RPSGameTest,WhenPlayerChooseScissorsAndComputerChoosePaperShouldResultInUSER_LOOSE){
    //ARRANGE
    char userChoice[] = "SCISSORS";
    int computerChoice = PAPER;  

    //ACT
    Game_Result result = decideWinner(userChoice, computerChoice); 

    //ASSERT
    ASSERT_EQ(result, User_Win);
}

