#include "../header/Redirect.h"

bool AppendOutput::evaluate(int Read, int Write)
{
	if((Command == nullptr) || (File == NULL))
		return false;

	if(File != NULL)
	{
		if((Write = open(File, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU)) == -1)
		{
			perror("Error Opening File");
			return false;
		}
	}

	return Command->evaluate(Read, Write);
}
