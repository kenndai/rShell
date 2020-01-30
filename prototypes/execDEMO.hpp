#ifndef __EXECDEMO_HPP__
#define __EXECDEMO_HPP__

#include <unistd.h>

void run () {			
	//strings are const char* in c++
	string executed = "./executed";

	char* args[] = {(char*)executed.c_str(), NULL};

	//char* const* = pointer to a const pointer to a char
	//args is a const char**, not char* const*	
	
	//execvp(const char* file, char *const argv[]);
	//const char, const pointer to a char
	//cant modify the contents of the char and cant modify what the pointer is pointing to
	execvp(args[0],args);	
}

#endif
