#include "../header/Add.h"
//#include "Parser.h"

using namespace std;

bool Add::evaluate() {
	/*
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
	
	if (Left == nullptr && right == nullptr)
		return false;
	if (Left == nullptr)
		return false;
	if (Right == nullptr)
	{
		Left->evaluate();
		return false;
	}
	*/
	if (Left->evaluate())
		return Right->evaluate();
	else
		return false;
}

