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

TEST(CommandTest, CommandTest) {
	string input = "test -e rshell";
	CMD command(input);
	EXPECT_EQ(command.execute(), true);
}

