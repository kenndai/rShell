#include "gtest/gtest.h"

//#include "Executer_test.cpp"
#include "Parser_test.cpp"
#include "AND_test.cpp"
#include "OR_test.cpp"
#include "SEMI_test.cpp"
#include "CMD_test.cpp"
#include "PAREN_test.cpp"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
 	return RUN_ALL_TESTS();
}
