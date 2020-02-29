#include "gtest/gtest.h"
#include "../header/AND.h"
#include "../header/CMD.h"

using namespace std;

TEST(andTEST, ANDGetLeftChild) {
	Token* andToken = new AND();
	string inputLeft = "echo hello";
	string inputRight = "echo world";
	Token* cmdTokenLeft = new CMD(inputLeft);
	Token* cmdTokenRight = new CMD(inputRight);
	andToken->assignLeftChild(cmdTokenLeft);
	andToken->assignRightChild(cmdTokenRight);
	EXPECT_EQ(andToken->getLeftChild(), cmdTokenLeft);
}

TEST(andTEST, ANDGetRightChild) {
        Token* andToken = new AND();
        string inputLeft = "echo hello";                                                                                                                       string inputRight = "echo world";                                                                                                                      Token* cmdTokenLeft = new CMD(inputLeft);                                                                                                              Token* cmdTokenRight = new CMD(inputRight); 
        andToken->assignLeftChild(cmdTokenLeft);
        andToken->assignRightChild(cmdTokenRight);
        EXPECT_EQ(andToken->getRightChild(), cmdTokenRight);
}

TEST(andTEST, ANDExecute) {
        Token* andToken = new AND();
        string inputLeft = "echo hello";
        string inputRight = "ls -a";
        Token* cmdTokenLeft = new CMD(inputLeft);
        Token* cmdTokenRight = new CMD(inputRight);
        andToken->assignLeftChild(cmdTokenLeft);
        andToken->assignRightChild(cmdTokenRight);
	EXPECT_EQ(andToken->execute(), true);	
}

TEST(andTEST, ANDInvalidExecute) {
        Token* andToken = new AND();
        string inputLeft = "echcaa hello";
        string inputRight = "ls -a";
        Token* cmdTokenLeft = new CMD(inputLeft);
        Token* cmdTokenRight = new CMD(inputRight);
        andToken->assignLeftChild(cmdTokenLeft);
        andToken->assignRightChild(cmdTokenRight);
	EXPECT_EQ(andToken->execute(), false);
}

