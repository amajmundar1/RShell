#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	pid_t pid, x;
	pid = fork();

	if (pid == 0) {
		execvp(argv[0], argv);
	}
	else if (pid > 0) {
		x = waitpid(-1, NULL, 0);
	}
	else {
		exit(-1);
	}

	exit(1);


return 0;
}
