#ifndef _TEST_H_
#define _TEST_H_
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <unistd.h>
#include "Command.h"

class Test: public Command {
	private: 
		vector<char*> Input;
		char* flag;
		vector<char*> file;
	public:
		Test(vector<char*> input);
		bool evaluate();
};

#endif
