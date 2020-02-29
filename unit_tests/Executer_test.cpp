#include "gtest/gtest.h"
#include "../header/Executer.h"

TEST(ExecuterTest, setExecuter()) {
	vector<Token*> tokenList;
	tokenList.push_back(new CMD(echo hello));
	tokenList.push_back(new AND());
	tokenList.push_back(new CMD(echo world));
	
}
