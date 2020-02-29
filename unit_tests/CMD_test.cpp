#include "gtest/gtest.h"
#include "../header/CMD.h"
#include <string>

using namespace std;

TEST(CommandTest, CommandEchoHelloWorld) {
	string input = "echo hello world";
	CMD command(input);
	EXPECT_EQ(command.execute(), true);
}

TEST(CommandTest, CommandInvalid) {
	string input = "echhaa hello world";
	CMD command(input);
	EXPECT_EQ(command.execute(), false);
}

TEST(CommandTest, CommandLs_a) {	
	string input = "ls -a";
	CMD command(input);
	EXPECT_EQ(command.execute(), true);
}

TEST(CommandTest, TestLiteral) {
	string input = "test -e rshell";
	CMD command(input);
	EXPECT_EQ(command.execute(), true);
}

TEST(CommandTest, TestSymbolic) {
	string input = "[-f rshell]";
	CMD command(input);
	EXPECT_EQ(command.execute(), true);
}

TEST(CommandTest, TestLiteralFalse) {
        string input = "test -f header";
        CMD command(input);
        EXPECT_EQ(command.execute(), false);
}

TEST(CommandTest, TestSymbolicFalse) {
	string input = "[-d rshell]";
	CMD command(input);
	EXPECT_EQ(command.execute(), false);
}

TEST(CommandTest, TestSymWhiteSpaces) {
	string input = "    test    -e       rshell";
	CMD command(input);
	EXPECT_EQ(command.execute(), true);
}

TEST(CommandTest, TestLitWhiteSpaces) {
	string input = "[   -e   rshell   ]";
	CMD command(input);
	EXPECT_EQ(command.execute(), true);
}

TEST(CommandTest, TestSymExistsFalse) {
	string input = "test -e asjdg";
	CMD command(input);
	EXPECT_EQ(command.execute(), false);
}

TEST(CommandTest, TestLitFileFalse) {
	string input = "[test -f asdgAsd]";
	CMD command(input);
	EXPECT_EQ(command.execute(), false);
}
