#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Parser
{
private:
	char *Input;
	char Delim;
public:
	Parser(char *input);
	vector<char*> Parse();
};
