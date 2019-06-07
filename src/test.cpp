#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../header/Test.h"


Test::Test(vector<char*> input) : Command(input) {
	Input = input;
}

bool Test::evaluate() {	
	//return true;
	struct stat testing;
	int status = stat(Input[2], &testing);
	if (Input.size() < 2)
	{
		cout << "No Path given" << endl;
		return false;
	}
	else if (Input.size() == 2) {
		if (stat(Input[1], &testing) == 0)
			return true;
	}
	else if (strcmp(Input[1], "-f") == 0) {
		if (stat(Input[2], &testing) == 0 && S_ISREG(testing.st_mode))
			return true;
	}
	else if (strcmp(Input[1], "-d") == 0) {
		if (stat(Input[2], &testing) == 0 && S_ISDIR(testing.st_mode))
                	return true;
	}
	else if (strcmp(Input[1], "-e") == 0) {
		if(stat(Input[2], &testing) == 0)
			return true;
	}
	else {
		cout << "(False)" << endl;
		return false;
	}
}
