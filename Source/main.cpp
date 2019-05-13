#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <unistd.h>
#include "Parser.h"

using namespace std;

int main()
{
	bool exit = false;
	string input;
	while (exit != true)
	{
		cout << "$ ";
		getline(cin, input);
		if (input == "exit")
			exit = true;
		else 
		{
			Parser* pars = new Parser(input);
			char** Param = pars->getParse();
			execvp(Param[0], Param);
		}

	}
}
