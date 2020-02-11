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

    private:

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

    if (cPid == 0) { //child process does the executing

        if ( (info[0] == "exit()") || (execvp(args[0], args) == -1) ) //checks for valid command to execute, exit status is 1 if nonvalid command passed in
            exit(1); //exit() sets the status to 1 for parent fork
        else
            exit(0);    //execvp() successfully ran

    } else if (cPid > 0) {  //parent process

        if (info[0] == "exit()")
            exit(0); //terminate

        waitpid(cPid, &status, 0); //wait for child to terminate

        if (WIFEXITED(status)) { //if process TERMINATES successfully
           int exitStatus = WEXITSTATUS(status);
           //std::cout << "Child process exit status: " << exitStatus << std::endl;

           if (exitStatus == 0) { //if command was EXECUTED successfully
                return true;
           } else
                return false;

        } else
            std::cout << "Child process didnt terminate successfully" << std::endl;
    }
    else
        std::cout << "cPid = -1, fork() failed" << std::endl; //testing purposes

    return false; //return true if the COMMAND was run successfully
}


#endif // COMMAND_H
