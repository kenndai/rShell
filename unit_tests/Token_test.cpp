#include "gtest/gtest.h"
#include "../header/Token.h"

#include <string>

TEST(TokenTest, TokenGetString) {
	string cmd = "hello world";
	Token test = Token(cmd);	
	EXPECT_EQ(test.getString(), "hello world");
}
TEST(TokenTest, GetStringComment) {
	string cmd = "hello# world";
	Token test(cmd);
	EXPECT_EQ(test.getString(), "hello# world");
}
TEST(TokenTest, GetInfoNotNULL) {
	string cmd = "hello world";
	Token test(cmd);
	EXPECT_TRUE(test.getInfo() != nullptr);
}
TEST(TokenTest, GetInfoString) {
	string cmd = "hello world";
	Token test(cmd);
	string first = *(test.getInfo());
	EXPECT_EQ(first, "hello");
}

