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
#include "../header/Redirect.h"
//#include "../header/Pipe.h"
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
			//for(int i = 0; i < Param.size(); i++)
			//	cout << Param[i] << endl;
			if(!Param.empty())
			{	
				ConstructTree* BuildTree = new ConstructTree(Param);
				stack<Command*> CMD = BuildTree->getCommands();
				stack<Operator*> OP = BuildTree->getOperators();
				stack<Redirect*> RD = BuildTree->getRedirect();

				if (!OP.empty())
					OP.top()->evaluate(0, 1);
				else if (!RD.empty())
					RD.top()->evaluate(0, 1);
				else
					CMD.top()->evaluate(0, 1);
			}
		}
	}
}
