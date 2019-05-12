#include "Or.h"

using namespace std;

string Or::evaluate() {
	pid_t pid, x;
	pid = fork();
	int status;

	if (pid == 0) {
		Parse or1 = new Parse(Left, " ");
		execvp(or1.parsed[0], or1.parsed);
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
				Parse or1 = new Parse(Right, " ");
				execvp(or1.parsed[0], or1.parsed);
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
