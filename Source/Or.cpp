#include "../header/Or.h"
#include "Parser.h"

using namespace std;

Or::Or()
{
	Left = NULL;
	Right = NULL;
}

Or::Or(Base* left, Base* right)
{
	Left = left;
	Right = right;
}

string Or::evaluate() {
	pid_t pid, x;
	pid = fork();
	int status;

	if (pid == 0) {
		Parser or2 = new Parser((char*)(Left->evaluate()).c_str());
		vector<char*> or1 = or2.Parse();
		execvp(or1[0], or1);
		perror("child failed");
	}
	else if (pid > 0) {
		x = waitpid(-1, &status, 0);
		if (x == -1) {
			perror("waitpid error");
			exit(-1);
		}
		else {
			if(!WIFEXITED(status){
				Parser or2 = new Parser((char*)(Right->evaluate()).c_str());
				vector<char*> or1 = or2.Parse();
				execvp(or1, or1);
				perror("parent failed");
				exit(-1);
			}
		}
	}
	else {
		perror("fork failed");
		exit(-1);
	}
	exit(1);
	return 0;
}
