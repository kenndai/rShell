#include "gtest/gtest.h"
#include "../header/Command.h"
#include <string>

using namespace std;

TEST(CommandTest, CommandEchoHelloWorld) {
	string info[2] = {"echo", "hello world"};
	string* ptr = info;
	Command command = Command(ptr);
	EXPECT_EQ(command.run(), true);
}

TEST(CommandTest, CommandInvalid) {
	string info[2] = {"echaaa", "hello world"};
	string* ptr = info;
	Command command(ptr);
	EXPECT_EQ(command.run(), false);
}

TEST(CommandTest, CommandLs_a) {	
	string info[3] = {"ls", "-a", "-l"};
	string* ptr = info;
	Command command(ptr);
	EXPECT_EQ(command.run(), true);
}

