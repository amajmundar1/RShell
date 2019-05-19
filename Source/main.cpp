#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <unistd.h>
#include "../header/Parser.h"
#include "../header/Command.h"

using namespace std;

int main()
{
	bool exit = false;
	string input = " ";
	while (exit != true)
	{
		cout << "$ ";
		getline(cin, input);
		if (input == "exit")
			exit = true;
		else 
		{
			Parser* pars = new Parser(input);
			vector<char*> Param = pars->Parse();
			for(int i = 0; i < Param.size(); ++i)
				cout << Param[i] << endl;
			execvp(Param[0], Param.data());
		}

	}
}
