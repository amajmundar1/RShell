#include "Semi.h"

using namespace std;

string Semi::evaluate() {
        pid_t pid, x;
        pid = fork();
        int status;

        if (pid == 0) {
                Parse semi = new Parse(Left, " ");
                execvp(semi.parsed[0], semi.parsed);
                perror("child failed");
        }
        else if (pid > 0) {
                Parse semi = new Parse(Right, " ");
                execvp(semi.parsed[0], semi.parsed);
                perror("parent failed");
        }
        else {
                perror("fork failed");
                exit(-1);
        }
        exit(1);
        return 0;
}

