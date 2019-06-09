#include "../header/Pipe.h"

bool Pipe::evaluate(int Read, int Write)
{
	int fd[2];

	if (pipe(fd) == -1)
		perror("Error Making Pipe");
	if ((Left == nullptr) || (Right == nullptr))
	{
		perror("Not Enough Arguments");
		return false;
	}
	
	if (Left->evaluate(Read, fd[1]) == false)
		return false;
	close(fd[1]);
	if (Right->evaluate(fd[0], Write) == false)
		return false;
	close(fd[0]);
	return true;
}
