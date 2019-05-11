#include <iostream>
#include <string>

using namespace std;

int main()
{
	exit = false;
	string input;
	vector<string> tokens;
	while (exit == false)
	{
		getline(cin, input);
		if (input == "exit")
			exit = true;

	}
}
