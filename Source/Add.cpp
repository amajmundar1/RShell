#include "../header/Add.h"
#include "Parser.h"

using namespace std;

Add::Add()
{
	Left = NULL;
	Right = NULL;
}

Add::Add(Base* left, Base* right)
{
	Left = left;
	Right = right;
}

string Add::evaluate() {
        pid_t pid, x;
        pid = fork();
        int status;

        if (pid == 0) {
                Parser* add1 = new Parser(Left->evaluate());
		char** add = add1->getParse();
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
                        if(WIFEXITED(status)){
                                Parser* add1 = new Parser(Right->evaluate());
                                char** add = add1->getParse();
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

