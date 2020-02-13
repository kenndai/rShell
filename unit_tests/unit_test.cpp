#include "gtest/gtest.h"

#include "Command_test.hpp" //change these to hpp test files
#include "Token_test.hpp"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
 	return RUN_ALL_TESTS();
}
