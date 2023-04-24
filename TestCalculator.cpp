#include <gtest/gtest.h>

extern "C" {
#include "calculator.h"
}

class calculatorTest : public testing::Test {
protected:
	void SetUp() override {
	}
};

TEST_F(calculatorTest,WhenAdding5and10ShouldResultBe15){
    //ARRANGE
    char op = '+';
    float operand1 = 5;
    float operand2 = 10;
    float result; 

    //ACT
    result = calculateAndPrint(operand1, operand2, op); 

    //ASSERT
    ASSERT_EQ(result,  15.00);
}
TEST_F(calculatorTest,WhenSubtracting5from10ShouldResultBe5){
    //ARRANGE
    char op = '-';
    float operand1 = 10;
    float operand2 = 5;
    float result; 

    //ACT
    result = calculateAndPrint(operand1, operand2, op); 

    //ASSERT
    ASSERT_EQ(result,  5.00);
}

TEST_F(calculatorTest,WhenMultiplying5and10ShouldResultBe50){
    //ARRANGE
    char op = '*';
    float operand1 = 5;
    float operand2 = 10;
    float result; 

    //ACT
    result = calculateAndPrint(operand1, operand2, op); 

    //ASSERT
    ASSERT_EQ(result,  50.00);
}

TEST_F(calculatorTest,WhenDividing10with5ShouldResultBe2){
    //ARRANGE
    char op = '/';
    float operand1 = 10;
    float operand2 = 5;
    float result; 

    //ACT
    result = calculateAndPrint(operand1, operand2, op); 

    //ASSERT
    ASSERT_EQ(result,  2.00);
}

TEST_F(calculatorTest,WhenCalculationRemainderOf5in10ShouldResultBe0){
    //ARRANGE
    char op = '%';
    float operand1 = 10;
    float operand2 = 5;
    float result; 

    //ACT
    result = calculateAndPrint(operand1, operand2, op); 

    //ASSERT
    ASSERT_EQ(result,  0.00);
}