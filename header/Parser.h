#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

class Parser
{
private:
	char *Input;
public:
	Parser(string input);
	Parser(char* input);
	vector<char*> ParseOperator();
	vector<char*> ParseOperand();
};
