#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "Parser.h"

using namespace std;

int main()
{
	bool exit = false;
	string input;
	//vector<string> tokens;
	while (exit != true)
	{
		cout << "$ ";
		getline(cin, input);
		if (input == "exit")
			exit = true;
		else 
		{
			Parser* pars = new Parser((char*)input.c_str());
                	vector<char*> parts = pars->Parse();
			char* Param[parts.size()];
			for(int i = 0; i < parts.size(); i++)
				Param[i] = parts[i];
			const char* file = parts[0];
			cout << file << endl;
			execvp(file, Param);
		}

	}
}
