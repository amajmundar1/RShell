#include "Base.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


class Command:public Base
{
	private:
		vector<char*> Input;
		bool empty;
	public:
		Command(vector<char*> input);
		bool execute();
};
