#ifndef COMMAND_H
#define COMMAND_H

#include "unistd.h"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

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

    if (cPid == 0) { //child process does the executing
	execvp(args[0], args);	//executes the command
    }
    else if (cPid > 0) {
 	waitpid(cPid, &status, 0); //if parent wait for child to terminate	
	if (WIFEXITED(status)) { //if process TERMINATES successfully
	   int exitStatus = WEXITSTATUS(status);
	   std::cout << "Child process exit status: " << exitStatus << std::endl;
	   if (exitStatus == 0) { //if command was EXECUTED successfully
		/*if a nonexecutable is at args[0] and execvp is called on it, exit status is still 0*/
		executed = true;	 
	   }
	}
    }
    else {
	std::cout << "fork() failed" << std::endl;
	exit = 1; //if exit command was called set exit variable to true
	_exit(1); //exit when fork fails	
    }
    // return true; /*original*/
    //return true if the COMMAND was run successfully
    return executed;   
}

bool Command::checkExit() {
    return this->exit;
}

#endif // COMMAND_H
