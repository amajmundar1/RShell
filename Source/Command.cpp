#include "../headers/Command.h"

Command::Command(vector<char*> input)
{
	if(input.empty())
		empty = true;
	else
	{
		Input = input;
		empty = false;
	}
}

bool Command::execute()
{
	if (empty == true)
		return false;
	pid_t pid;
        pid = fork();
        int status;

        if (pid == -1) 
	{
		perror("Error Creating Process");
		exit(1);
        }
        else if (pid == 0) 
	{
		if (execvp(Input[0], Input.data()) == -1)
		{
			perror("Command not Found");
			exit(1);
		}
		else
			exit(0);
	}

	if (waitpid(pid, &status, 0) == -1)
		perror("Waitpid Error");
	if (WEXITSTATUS(status) == 0)
		return true;
	return false;

	/*
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
	*/
}
