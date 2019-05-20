#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <unistd.h>
#include "../header/Parser.h"
#include "../header/Command.h"
#include "../header/Add.h"
#include "../header/Or.h"
#include "../header/Semi.h"

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
		else 
		{
			Parser* pars = new Parser(input);
			vector<char*> Param = pars->Parse1();
			vector<Command*> CMD;
			vector<Add*> ADD;
			vector<Semi*> SEMI;
			vector<Or*> OR;
			
			for(int i = 0; i < Param.size(); i++)
			{
				if (strcmp(Param[i], "&&") == 0)
				{
					if (strcmp(Param[i-2], "&&") == 0)
						ADD.push_back(new Add(ADD[ADD.size()-1], CMD[CMD.size()-1]));
					else if (strcmp(Param[i-2], "||") == 0)
						ADD.push_back(new Add(OR[OR.size()-1], CMD[CMD.size()-1]));
					else if (strcmp(Param[i-2], ";") == 0)
						ADD.push_back(new Add(SEMI[OR.size()-1], CMD[CMD.size()-1]));
					else
						ADD.push_back(new Add(CMD[CMD.size()-1], CMD[CMD.size()-2]));
				}
				else if (strcmp(Param[i], "||") == 0)
				{
					if (strcmp(Param[i-2], "&&") == 0)
                                                OR.push_back(new Or(ADD[ADD.size()-1], CMD[CMD.size()-1]));
                                        else if (strcmp(Param[i-2], "||") == 0)
                                                OR.push_back(new Or(OR[OR.size()-1], CMD[CMD.size()-1]));
                                        else if (strcmp(Param[i-2], ";") == 0)
                                                OR.push_back(new Or(SEMI[OR.size()-1], CMD[CMD.size()-1]));
                                        else
                                                OR.push_back(new Or(CMD[CMD.size()-1], CMD[CMD.size()-2]));
				}
				else if (strcmp(Param[i], ";") == 0)
				{
					if (strcmp(Param[i-2], "&&") == 0)
                                                SEMI.push_back(new Semi(ADD[ADD.size()-1], CMD[CMD.size()-1]));
                                        else if (strcmp(Param[i-2], "||") == 0)
                                                SEMI.push_back(new Semi(OR[OR.size()-1], CMD[CMD.size()-1]));
                                        else if (strcmp(Param[i-2], ";") == 0)
                                                SEMI.push_back(new Semi(SEMI[OR.size()-1], CMD[CMD.size()-1]));
                                        else
                                                SEMI.push_back(new Semi(CMD[CMD.size()-1], CMD[CMD.size()-2]));
				}
				else
				{
					Parser* sub_parse = new Parser(Param[i]);
					vector<char*> newParam = sub_parse->Parse();
					CMD.push_back(new Command(newParam));
				}
			}
			if (strcmp(Param[Param.size()-1], "&&") == 0)
				ADD[ADD.size()-1]->evaluate();
			else if (strcmp(Param[Param.size()-1], "||") == 0)
				OR[OR.size()-1]->evaluate();
			else if (strcmp(Param[Param.size()-1], ";") == 0)
				SEMI[SEMI.size()-1]->evaluate();
			else
				CMD[CMD.size()-1]->evaluate();
		}
	}
}
