#CMakeLists File
# This file should run two instructions
# rshell (builds the main exe)
# test (runs unit tests)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rShell
    src/rShell.cpp
    header/Command.h
    header/Executer.h
    header/Parser.h
    header/Token.h
    header/TrimWhiteSpace.h
)

ADD_EXECUTABLE(test
	unit_tests/unit_test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
