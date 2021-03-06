#CMakeLists File
# This file should run two instructions
# rshell (builds the main exe)
# test (runs unit tests)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(
	rshell

	src/rShell.cpp
	src/Executer.cpp
	src/Parser.cpp
	src/Token.cpp
	src/CMD.cpp
	src/AND.cpp
	src/OR.cpp
	src/SEMI.cpp
	src/PAREN.cpp
	src/TrimWhiteSpaces.cpp
	header/TrimWhiteSpaces.h
	header/Executer.h
	header/Parser.h
	header/Token.h
	header/CMD.h
	header/OR.h
	header/AND.h
	header/SEMI.h
	header/PAREN.h

)

ADD_EXECUTABLE(
	test
	unit_tests/unit_test.cpp
	src/Executer.cpp
	src/Parser.cpp
	src/Token.cpp
	src/CMD.cpp
	src/AND.cpp
	src/OR.cpp
	src/SEMI.cpp
	src/PAREN.cpp
	src/TrimWhiteSpaces.cpp
)	

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
