#include "../header/Semi.h"
//#include "Parser.h"

using namespace std;

bool Semi::evaluate() {
	/*
        pid_t pid, x;
        pid = fork();

        if (pid == 0) {
                Parser* semi1 = new Parser(Left->evaluate());
                char** semi = semi1->getParse();
		execvp(semi[0], semi);
                perror("child failed");
        }
        else if (pid > 0) {
                Parser* semi1 = new Parser(Right->evaluate());
		char** semi = semi1->getParse();
                execvp(semi[0], semi);
                perror("parent failed");
        }
        else {
                perror("fork failed");
                exit(-1);
        }
        exit(1);
        return 0;
	*/
	if (Left != nullptr)
		Left->evaluate();
	if (Right != nullptr)
		return Right->evaluate();
	return false;
}

