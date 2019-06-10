#include "../header/Redirect.h"

bool RedirectInput::evaluate(int Read, int Write)
{
	if((Command == nullptr) || (File == NULL))
		return false;

	if(File != NULL)
	{
		if (File[strlen(File) -1] == ' ')
			File[strlen(File) -1] = '\0';
		Read = open(File, O_RDONLY);
		if(Read == -1)
		{
			perror("File Could not be Opened");
			return false;
		}
	}

	return Command->evaluate(Read, Write);
}
