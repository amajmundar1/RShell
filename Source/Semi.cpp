#include "Semi.h"

using namespace std;

string Semi::evaluate() {
        pid_t pid, x;
        pid = fork();

        if (pid == 0) {
                Parser semi1 = new Parser(Left);
                vector<char*> semi = or1.Parse();
		execvp(semi[0], semi);
                perror("child failed");
        }
        else if (pid > 0) {
                Parser semi1 = new Parser(Right);
		vector<char*> semi = semi1.Parse();
                execvp(semi[0], semi);
                perror("parent failed");
        }
        else {
                perror("fork failed");
                exit(-1);
        }
        exit(1);
        return 0;
}

