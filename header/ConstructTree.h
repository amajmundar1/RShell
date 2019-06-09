#pragma once

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <unistd.h>
#include "Parser.h"
#include "Command.h"
#include "Operator.h"
#include "Add.h"
#include "Or.h"
#include "Semi.h"
#include "Pipe.h"
#include "Redirect.h"

using namespace std;

class ConstructTree
{
	private:
		vector<char*> Param;
		stack<Command*> CMD;
		stack<Operator*> OP;
		stack<Redirect*> RD;
	public:
		ConstructTree(vector<char*> param);
		void MakeTree();
		stack<Command*> getCommands();
		stack<Operator*> getOperators();
		stack<Redirect*> getRedirect();
};
