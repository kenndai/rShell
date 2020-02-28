#ifndef CMD_H
#define CMD_H

#include <iostream>
#include "Token.h"
#include "TrimWhiteSpaces.h"
#include "unistd.h"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

class CMD : public Token{

    public:

        std::string info[3];

        CMD(std::string cmdStr);
        ~CMD();

        virtual bool execute();
        virtual std::string tokenType();
        virtual void assignLeftChild(Token* t);
        virtual void assignRightChild(Token* t);
        virtual Token* getLeftChild();
        virtual Token* getRightChild();

        CMD operator=(const CMD &other);

    private:

        TrimWhiteSpaces *trimmer;
        std::string val = "CMD";
        bool bracketsFound = false;

        void extractInfo(std::string &str);
        std::string& removeQuotations(std::string &str);
        std::string& removeBrackets(std::string &str);
        void convertToTestCmd();
	bool runTest();

};

CMD::CMD(std::string cmdStr) {
    trimmer->trimBothWhiteSpaces(cmdStr);
    extractInfo(cmdStr);
}

CMD::~CMD() {
    /* nukem() */
}

void CMD::assignLeftChild(Token* t) {

}

void CMD::assignRightChild(Token* t) {

}

Token* CMD::getLeftChild() {
    return nullptr;
}

Token* CMD::getRightChild() {
    return nullptr;
}

void CMD::extractInfo(std::string &str) {
    std::string space = " ";
    std::string tempArg;
    size_t pos;

    if (str.length() > 2)   //don't run removeBrackets on an empty string
        str = removeBrackets(str);

    for (unsigned int i = 0; i < 3; i++) {
        if ( (pos = str.find(space)) != std::string::npos ) {   //next space found
            tempArg = str.substr(0, pos);
            str.erase(0, pos);
        } else if ( (str.length() != 0) && (str.find(space) == std::string::npos) ) { //no spaces left but still need to append rest of string
            tempArg = str;
            str = "";
        } else {
            tempArg = "";
        }

        if (tempArg != "") { //if string isn't empty
            if (i == 1) //if second argument
                info[i] = removeQuotations(tempArg);
            else
                info[i] = tempArg;
        }

        trimmer->trimLeftWhiteSpaces(str);
    }
    if (bracketsFound)
        convertToTestCmd();

}

void CMD::convertToTestCmd() {
    info[2] = info[1];
    info[1] = info[0];
    info[0] = "test";
}

std::string& CMD::removeBrackets(std::string &str) {
    if ( (str.at(0) == '[') && (str.at(str.length()-1) == ']') )
    {
        str = str.substr(1, str.length()-2);
        this->bracketsFound = true;
    }
    return str;
}

std::string& CMD::removeQuotations(std::string &str) {
    str.erase( remove( str.begin(), str.end(), '\"' ), str.end() );
    return str;
}

bool CMD::execute() {
    int status;
    bool testStatus; //did runTest return true or false

    char* args[3] = {(char*)info[0].c_str(), NULL, NULL};

    if (info[1] != "") {
        args[1] = (char*)info[1].c_str();
        args[2] = NULL;
    }

    pid_t cPid = fork(); //forks the process

    if (cPid == 0) { //child process does the executing

        if ( (info[0] == "exit") || (info[0] == "") ) //if empty command or "exit()" just terminate
            exit(0);
	else if ( info[0] == "test" ) {
	    testStatus = runTest();
	    if (testStatus) { //if path exists
		std::cout << "(True)" << std::endl;
		exit(0);
	    }
	    else {
		std::cout << "(False)" << std::endl;
		exit(1);
	    }
	}
        else if ( execvp(args[0], args) == -1 ) { //checks for valid command to execute, exit status is 1 if nonvalid command passed in
            std::cout << "-bash: " << info[0] << ": command not found" << std::endl;
            exit(1); //exit() sets the status to 1 for parent fork
        } else
            exit(0);    //execvp() successfully ran

    } else if (cPid > 0) {  //parent process

        if (info[0] == "exit")
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

bool CMD::runTest() {
	struct stat buffer;
	mode_t fileMode;

	stat((char*)info[2].c_str(), &buffer); //pass in path, store info in buffer
	fileMode = buffer.st_mode; //returns mode_t of buffer

	if ( info[1] != "-e" || info[1] != "-f" || info[1] != "-d" ) {
		std::cout << "-bash: test: " << info[1] << ": unary operator expected" << std::endl;
		return false;
	}
	else {
		if ( S_ISREG(fileMode) || S_ISDIR(fileMode) ) //checks fileMode for reg or dir
			return true;
		else
			return false;
	}
}

std::string CMD::tokenType() {
    return val;
}

CMD CMD::operator=(const CMD &other) {
    if(this != &other) {
        for (unsigned int i = 0; i < info->size(); i++)
            this->info[i] = other.info[i];
    }
    return *this;
}

#endif // COMMAND_H
