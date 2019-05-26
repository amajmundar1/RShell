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

using namespace std;

class ConstructTree
{
	private:
		vector<char*> Param;
		stack<Command*> CMD;
		stack<Operator*> OP;
	public:
		ConstructTree(vector<char*> param);
		void MakeTree();
		stack<Command*> getCommands();
		stack<Operator*> getOperators();
};
