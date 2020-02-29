#include "gtest/gtest.h"
#include "../header/PAREN.h"

TEST(parenTEST, PARENGetLeftChild) {
	string lBracket = "(";
        Token* parenToken = new PAREN(lBracket);
        EXPECT_EQ(parenToken->getLeftChild(), nullptr);
}

TEST(parenTEST, PARENGetRightChild) {
	string rBracket = ")";
        Token* parenToken = new PAREN(rBracket);
        EXPECT_EQ(parenToken->getRightChild(), nullptr);
}
