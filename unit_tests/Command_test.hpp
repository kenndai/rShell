#ifndef COMMAND_TEST_HPP
#define COMMAND_TEST_HPP 

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

#endif
