#include "../header/Command.h"

Command::Command(vector<char*> input)
{
	if(input.empty())
		empty = true;
	else
	{
		Input = input;
		cout << Input[0] << endl;
		empty = false;
	}
}

bool Command::evaluate()
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
}
