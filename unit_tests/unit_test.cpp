#include "gtest/gtest.h"

#include "Command_test.cpp"
#include "Token_test.cpp"
#include "Executer_test.cpp"
#include "Parser_test.cpp"
#include "../header/Read.h"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
 	return RUN_ALL_TESTS();
}
