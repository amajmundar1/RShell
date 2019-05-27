#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <unistd.h>
#include "../header/Parser.h"
#include "../header/Command.h"
#include "../header/Operator.h"
#include "../header/Add.h"
#include "../header/Or.h"
#include "../header/Semi.h"
#include "../header/Test.h"
#include "../header/ConstructTree.h"

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
		else if(input.empty())
			exit = false;
		else 
		{
			Parser* pars = new Parser(input);
			vector<char*> Param = pars->ParseOperator();
			if(!Param.empty())
			{	
				ConstructTree* BuildTree = new ConstructTree(Param);
				stack<Command*> CMD = BuildTree->getCommands();
				stack<Operator*> OP = BuildTree->getOperators();

				if (!OP.empty())
					OP.top()->evaluate();
				else
					CMD.top()->evaluate();
			}
		}
	}
}
