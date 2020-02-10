#ifndef COMMAND_H
#define COMMAND_H

#include "unistd.h"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

class Command {

    public:

        Command(std::string *info);
        ~Command();
        bool run();
        bool checkExit();

    private:
	bool executed = false;
        bool exit = false;
        std::string info[2];
};

Command::Command(std::string *info) {
    this->info[0] = info[0]; //executable
    this->info[1] = info[1]; //argument list
}

Command::~Command() {
    //nukem()
}

bool Command::run() {
    //fork(), execvp(), waitpid()
    int status;
    char* args[] = {(char*)info[0].c_str(), (char*)info[1].c_str(), NULL}; //create char* array based on string array

    pid_t cPid = fork(); //forks the process

    std::cout << info[0] << " " << info[1] << std::endl;    //just for testing purposes to see which commands were called
   
    if (info[0] == "exit") {
	exit = true;
	return executed;
    }
		
    if (cPid == 0) { //child process does the executing
	if (execvp(args[0], args == -1) //checks for valid command to execute, exit status is 1 if nonvalid command passed in
		exit(EXIT_FAILURE);
	execvp(args[0], args);	
    }
    else if (cPid > 0) {
 	waitpid(cPid, &status, 0); //wait for child to terminate	
	if (WIFEXITED(status)) { //if process TERMINATES successfully
	   int exitStatus = WEXITSTATUS(status);
	   std::cout << "Child process exit status: " << exitStatus << std::endl;
	   if (exitStatus == 0) { //if command was EXECUTED successfully
		executed = true;	 
	   }
	}
    }
    else {
	std::cout << "fork() failed" << std::endl;
	//exit = 1; //if exit command was called set exit variable to true
    }
    // return true; /*original*/
    return executed; //return true if the COMMAND was run successfully
}

bool Command::checkExit() {
    return this->exit;
}

#endif // COMMAND_H
