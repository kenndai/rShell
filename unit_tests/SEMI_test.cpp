#include "gtest/gtest.h"
#include "../header/SEMI.h"  

TEST(semiTEST, SEMIGetLeftChild) {
        Token* semiToken = new SEMI();
//        string inputLeft = "echo hello";
//        Token* cmdTokenLeft = new CMD(inputLeft);
//        semiToken->assignLeftChild(cmdTokenLeft);
        EXPECT_EQ(semiToken->getLeftChild(), nullptr);
}

TEST(semiTEST, SEMIGetRightChild) {
	Token* semiToken = new SEMI();
	EXPECT_EQ(semiToken->getRightChild(), nullptr);	
}
