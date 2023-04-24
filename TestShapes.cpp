 #include <gtest/gtest.h>


extern "C" {
#include "shapes.h"
#include "supportFunctions.h"
}

class ShapesTest : public testing::Test {
protected:
	void SetUp() override {
		//game_initialize();	/* Without this the Tests could break*/
	}
};

TEST_F(ShapesTest,WhenCalculatingAreaOfARectangleWithBase10cmAndHeight5cmShouldReturn50CM2){
    //ARRANGE
    #define RECTANGEL 1
    float area; 

    //ACT
    area = calculateArea(10, 5, RECTANGEL); 

    //ASSERT
    ASSERT_EQ(area,  50.00);
}

TEST_F(ShapesTest,WhenCalculatingAreaOfParallelogramWithBase10cmAndHeight5cmShouldReturn50CM2){
    //ARRANGE
    #define PARALLELOGRAM 2
    float area; 

    //ACT
    area = calculateArea(10, 5, PARALLELOGRAM); 

    //ASSERT
    ASSERT_EQ(area,  50.00);
}

TEST_F(ShapesTest,WhenCalculatingAreaOfTriangleWithBase10cmAndHeight5cmShouldReturn25CM2){
    //ARRANGE
    #define TRIANGLE 3
    float area; 

    //ACT
    area = calculateArea(10, 5, TRIANGLE); 

    //ASSERT
    ASSERT_EQ(area,  25.00);
}

TEST_F(ShapesTest,WhenCalculatingAreaOfCircleWithRadius5CMShouldReturn78CM2){
    //ARRANGE
    #define CIRCLE 4
    float area; 

    //ACT
    area = calculateArea(5, 0, CIRCLE ); 

    //ASSERT
    ASSERT_NEAR(area,  78.54, 0.02);
}

TEST_F(ShapesTest,WhenCalculatingCircumferenceOfRectangleWithBase10cmAndHeight5cmShouldReturn30CM2){
    //ARRANGE
    #define RECTANGLE 1
    float circumference; 

    //ACT
    circumference = calculateCircumference(10, 5, 0, RECTANGLE); 

    //ASSERT
    ASSERT_EQ(circumference,  30.00);
}

TEST_F(ShapesTest,WhenCalculatingCircumferenceOfParallelogramWithBase10cmAndHeight5cmShouldReturn30CM2){
    //ARRANGE
    #define PARALLELOGRAM 2
    float circumference; 

    //ACT
    circumference = calculateCircumference(10, 5, 0, PARALLELOGRAM); 

    //ASSERT
    ASSERT_EQ(circumference,  30.00);
}

TEST_F(ShapesTest,WhenCalculatingCircumferenceOfTriangleWithBase10cmAndHeight5cmAndLenght10cmShouldReturn25CM2){
    //ARRANGE
    #define TRIANGLE 3
    float circumference; 

    //ACT
    circumference = calculateCircumference(10, 5, 10, TRIANGLE); 

    //ASSERT
    ASSERT_EQ(circumference,  25.00);
}

TEST_F(ShapesTest,WhenCalculatingCircumferenceOfCircleWithRadius5CMShouldReturn31CM2){
    //ARRANGE
    #define CIRCLE 4
    float circumference; 

    //ACT
    circumference = calculateCircumference(5, 0, 0, CIRCLE); 

    //ASSERT
    ASSERT_NEAR(circumference,  31.42, 0.02);
}