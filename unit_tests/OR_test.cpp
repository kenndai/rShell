#include "gtest/gtest.h"
#include "../header/OR.h"  

TEST(orTEST, ORGetLeftChild) {
        Token* orToken = new OR();
        string inputLeft = "echo hello";
        string inputRight = "echo world";
        Token* cmdTokenLeft = new CMD(inputLeft);
        Token* cmdTokenRight = new CMD(inputRight);
        orToken->assignLeftChild(cmdTokenLeft);
        orToken->assignRightChild(cmdTokenRight);
        EXPECT_EQ(orToken->getLeftChild(), cmdTokenLeft);
}

TEST(orTEST, ORGetRightChild) {
        Token* orToken = new OR();
        string inputLeft = "echo hello";                                                                                                                       string inputRight = "echo world";                                                                                                                      Token* cmdTokenLeft = new CMD(inputLeft);                                                                                                              Token* cmdTokenRight = new CMD(inputRight);
        orToken->assignLeftChild(cmdTokenLeft);
        orToken->assignRightChild(cmdTokenRight);
        EXPECT_EQ(orToken->getRightChild(), cmdTokenRight);
}

TEST(orTEST, ORExecute) {
        Token* orToken = new OR();
        string inputLeft = "echo hello";
        string inputRight = "ls -a";
        Token* cmdTokenLeft = new CMD(inputLeft);
        Token* cmdTokenRight = new CMD(inputRight);
        orToken->assignLeftChild(cmdTokenLeft);
        orToken->assignRightChild(cmdTokenRight);
        EXPECT_EQ(orToken->execute(), true);
}

TEST(orTEST, OROneInvalid) {
        Token* orToken = new OR();
        string inputLeft = "echcaa hello";
        string inputRight = "ls -a";
        Token* cmdTokenLeft = new CMD(inputLeft);
        Token* cmdTokenRight = new CMD(inputRight);
        orToken->assignLeftChild(cmdTokenLeft);
        orToken->assignRightChild(cmdTokenRight);
        EXPECT_EQ(orToken->execute(), true);
}

TEST(orTEST, ORInvalid) {
	Token* orToken = new OR();
        string inputLeft = "echcaa hello";
        string inputRight = "lsa -a";
        Token* cmdTokenLeft = new CMD(inputLeft);
        Token* cmdTokenRight = new CMD(inputRight);
        orToken->assignLeftChild(cmdTokenLeft);
        orToken->assignRightChild(cmdTokenRight);
        EXPECT_EQ(orToken->execute(), false);                                                                                                           }   

