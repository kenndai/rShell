#include "gtest/gtest.h"
#include "../header/Executer.h"
#include <iostream>
#include <vector>

using namespace std;

TEST(ExecuterTest, setExecuterTrue) {
	Executer* exec = new Executer();
	vector<Token*> tokenList;
	string lBracket = "(";
	string rBracket = ")";
	string input1 = "echo hello";
	string input2 = "echo world";
	string input3 = "bye";
	tokenList.push_back(new PAREN(lBracket));
	tokenList.push_back(new CMD(input1));
	tokenList.push_back(new AND());
	tokenList.push_back(new CMD(input2));
	tokenList.push_back(new PAREN(rBracket));
	tokenList.push_back(new OR());
	tokenList.push_back(new CMD(input3));
	exec->setExecuter(tokenList);
	EXPECT_EQ(tokenList.at(0)->tokenType(), "OR");
}
