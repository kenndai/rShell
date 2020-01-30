#include <unistd.h>
#include <iostream>

using namespace std;

int main() {
	cout << "this is exec.cpp" << endl;
		
	if (fork() > 0)  { //initial fork here
		cout << "this is parent 1" << endl;
	}
	else if (fork() == 0) { //fork returns 0 here, child
		cout << "this is child of parent 1" << endl;
		if (fork() > 0) { //child forks here
			cout << "this is parent 2" << endl;	
		}
		else if (fork() == 0) {
			cout << "this is child of parent 2" << endl;
		}
	}

	return 0;
}
