#include "Add.h"

using namespace std;

string Add::evaluate() {
        pid_t pid, x;
        pid = fork();
        int status;

        if (pid == 0) {
                Parse add = new Parse(Left, " ");
                execvp(add.parsed[0], add.parsed);
                perror("child failed");
        }
        else if (pid > 0) {
                x = waitpid(-1, &status, 0);
                if (x == -1) {
                        perror("waitpid failed");
                        exit(-1);
                }
                else {
                        if(WIFEXITED(status){
                                Parse add = new Parse(Right, " ");
                                execvp(add.parsed[0], add.parsed);
                                perror("parent failed");
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

