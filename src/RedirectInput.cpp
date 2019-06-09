#include "../header/Redirect.h"

bool RedirectInput::evaluate(int Read, int Write)
{
	if((Command == nullptr) || (File == NULL))
		return false;

	if(File != NULL)
	{
		if((Read = open(File, O_RDONLY)) == -1)
		{
			perror("File Could not be Opened");
			return false;
		}
	}

	return Command->evaluate(Read, Write);
}
