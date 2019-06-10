#include "../header/Redirect.h"

bool RedirectOutput::evaluate(int Read, int Write)
{
	if ((Command == nullptr) || (File == NULL))
		return false;

	if(File != NULL)
	{
		Write = open(File, O_WRONLY | O_TRUNC | O_CREAT , S_IRWXU);
		if(Write == -1)
		{
			perror("Error Opening File");
			return false;
		}
	}

	return Command->evaluate(Read, Write);
}
