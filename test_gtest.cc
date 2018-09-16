
#include "gtest/gtest.h"

bool func(int x){
    if(x % 2 == 0){
        return true;
    }else{
        return false;
    }
}

TEST(funcTest,Negative){
    EXPECT_EQ(true, -2);
}

TEST(funcTest,Zero){
    EXPECT_EQ(true, 0);
}

TEST(funcTest,Positive){
    EXPECT_EQ(true, 2);
}

/*
int main(){
    RUN_ALL_TESTS();


    return 0;
}
*/
