#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

class Parser
{
private:
	char *Input;
	vector<char*> Tokens;
public:
	Parser(string input);
	void Parse();
	char* getParse();
};
