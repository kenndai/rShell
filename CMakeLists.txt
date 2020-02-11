#CMakeLists File
# This file should run two instructions
# rshell (builds the main exe)
# test (runs unit tests)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(
	rShell
    src/rShell.cpp
    header/Command.h
    header/Executer.h
    header/Parser.h
    header/Token.h
    header/TrimWhiteSpace.h
)
