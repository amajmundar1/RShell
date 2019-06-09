#include "../header/Command.h"
#include "../header/Test.h"

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

bool Command::evaluate(int Read, int Write)
{
	if (empty == true)
		return false;
	if (strcmp(Input[0], "test") == 0) {
		Test* test = new Test(Input);
		return test->evaluate(Read, Write);
	}

	Input.push_back(NULL);
	
	int STD_IN;
	int STD_OUT;

	if ((STD_IN = dup(0)) == -1)
		perror("Unable to Duplicate Stream");
	if ((STD_OUT = dup(1)) == -1)
		perror("Unable to Duplicate Stream");

	if (dup2(Read, 0) == -1)
		perror("Unable to Duplicate Stream");
	if (dup2(Write, 1) == -1)
		perror("Unable to Duplicate Stream");

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

	if (dup2(STD_IN, 0) == -1)
		perror("Error Resetting Stream");
	if (dup2(STD_OUT, 1) == -1)
		perror("Error Resetting Stream");

	if (WEXITSTATUS(status) == 0)
		return true;
	return false;
}
