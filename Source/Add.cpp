#include "Add.h"

using namespace std;

string Add::evaluate() {
        pid_t pid, x;
        pid = fork();
        int status;

        if (pid == 0) {
                Parser add1 = new Parser(Left);
		vector<char*> add = add1.Parse();
                execvp(add[0], add);
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
                                Parser add1 = new Parser(Right);
                                vector<char*> add = add1.Parse();
				execvp(add[0], add);
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

