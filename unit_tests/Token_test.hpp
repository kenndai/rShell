#ifndef TOKEN_TEST_HPP
#define TOKEN_TEST_HPP

#include "gtest/gtest.h"
#include "../header/Token.h"
#include <string>

TEST(TokenTest, TokenGetString) {
	string cmd = "hello world";
	Token test = Token(cmd);	
	EXPECT_EQ(test.getString(), "hello world");
}
/*
TEST(TokenTest, TokenGetInfo) {
	string cmd = "hello world";
	Token test = Token(cmd);
	EXPECT_EQ(test.getInfo(), );
}

TEST(TokenTest, TokenQuotations) {
	string cmd = "\"hello world\"";
	Token test = Token(cmd);
	EXPECT_EQ(test.getInfo(), );
}

TEST(TokenTest, TokenComments) {
	string cmd = "hell#o world";
	Token test(cmd);
	EXPECT_EQ(test.getInfo(), );
}
*/
#endif
