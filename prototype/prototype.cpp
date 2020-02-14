#include "unistd.h"
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
	
	string lsExec = "ls";
	string ls_lExec = "-l";
	char* args[] = {(char*)lsExec.c_str(), (char*)ls_lExec.c_str()};
	
	int status; //set to to NULL when child terminates
	pid_t cPid;  //pid of child

	cPid = fork(); //process is forked, cPid is assigned child's pid or 0

	if (cPid == 0) { //if child
		cout << "I am child" << endl;
		cout << "running ls" << endl;
		execvp(args[0], args);
	} 
	else if (cPid > 0) { //if parent
		cout << "I am parent" << endl;
		waitpid(cPid, &status, 0); //wait for the child with pid of cPid to finish 
		if (WIFEXITED(status)) { //returns nonzero if child terminated normally
			cout << "Child process exit status: " << WEXITSTATUS(status) << endl;
		}
	}
	else { //if fork failed
		cout << "fork() failed" << endl;
		_exit(1); //_exit when child fails
	}

	return 0;
}
