#include <iostream>
#include <string>
#include <tuple>
#include <unistd.h>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

class Parser
{
private:
	char *Input;
	vector<char*> Tokens;
public:
	Parser(string input);
	void Parse();
	char** getParse();
	int getSize();
};
