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
