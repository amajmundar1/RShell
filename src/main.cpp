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

			stack<Command*> CMD;
			stack<Operator*> OP;

			for (int i = 0; i < Param.size(); i++)
			{
				if(strcmp(Param[i] , "&&") == 0)
				{
					if (CMD.empty())
					{
						Operator* right = OP.top();
						OP.pop();
						Operator* left = OP.top();
						OP.push(right);
						OP.push(new Add(left, right));
					}
					else if ((strcmp(Param[i-1], "&&") != 0) && (strcmp(Param[i-1], "||") != 0) && (strcmp(Param[i-1], ";") != 0))
					{
						if ((strcmp(Param[i-2], "&&") != 0) && (strcmp(Param[i-2], "||") != 0) && (strcmp(Param[i-2], ";") != 0))
						{
							Command* right = CMD.top();
							CMD.pop();
							Command* left = CMD.top();
							CMD.pop();
							OP.push(new Add(left, right));
						}
						else
						{
							Operator* left = OP.top();
							Command* right = CMD.top();
							CMD.pop();
							OP.push(new Add(left, right));
						}
					}
					else
					{
						if ((strcmp(Param[i-2], "&&") != 0) && (strcmp(Param[i-2], "||") != 0) && (strcmp(Param[i-2], ";") != 0))
						{
							Command* left = CMD.top();
							CMD.pop();
							Operator* right = OP.top();
							OP.push(new Add(left, right));
						}
						else
						{
							Operator* right = OP.top();
							OP.pop();
							Operator* left = OP.top();
							OP.push(right);
							OP.push(new Add(left, right));
						}
					}
				}
				else if(strcmp(Param[i] , "||") == 0)
                                {
					if (CMD.empty())
					{
						Operator* right = OP.top();
                                                OP.pop();
                                                Operator* left = OP.top();
                                                OP.push(right);
                                                OP.push(new Or(left, right));
					}
					else if ((strcmp(Param[i-1], "&&") != 0) && (strcmp(Param[i-1], "||") != 0) && (strcmp(Param[i-1], ";") != 0))
                                        {
                                                if ((strcmp(Param[i-2], "&&") != 0) && (strcmp(Param[i-2], "||") != 0) && (strcmp(Param[i-2], ";") != 0))
                                                {
                                                        Command* right = CMD.top();
                                                        CMD.pop();
                                                        Command* left = CMD.top();
                                                        CMD.pop();
                                                        OP.push(new Or(left, right));
                                                }
                                                else
                                                {
							Operator* left = OP.top();
                                                        Command* right = CMD.top();
                                                        CMD.pop();
                                                        OP.push(new Or(left, right));

                                                }
                                        }
                                        else
                                        {
                                                if ((strcmp(Param[i-2], "&&") != 0) && (strcmp(Param[i-2], "||") != 0) && (strcmp(Param[i-2], ";") != 0))
                                                {
                                                        Command* left = CMD.top();
                                                        CMD.pop();
                                                        Operator* right = OP.top();
                                                        OP.push(new Or(left, right));
                                                }
                                                else
                                                {
                                                        Operator* right = OP.top();
                                                        OP.pop();
                                                        Operator* left = OP.top();
							OP.push(right);
                                                        OP.push(new Or(left, right));
                                                }
                                        }
                                }
				else if(strcmp(Param[i] , ";") == 0)
                                {
					if (CMD.empty())
					{
						Operator* right = OP.top();
                                                OP.pop();
                                                Operator* left = OP.top();
                                                OP.push(right);
                                                OP.push(new Semi(left, right));
					}
					else if ((strcmp(Param[i-1], "&&") != 0) && (strcmp(Param[i-1], "||") != 0) && (strcmp(Param[i-1], ";") != 0))
                                        {
                                                if ((strcmp(Param[i-2], "&&") != 0) && (strcmp(Param[i-2], "||") != 0) && (strcmp(Param[i-2], ";") != 0))
                                                {
                                                        Command* right = CMD.top();
                                                        CMD.pop();
                                                        Command* left = CMD.top();
                                                        CMD.pop();
                                                        OP.push(new Semi(left, right));
                                                }
                                                else
                                                {
                                                        Operator* left = OP.top();
                                                        Command* right = CMD.top();
                                                        CMD.pop();
                                                        OP.push(new Semi(left, right));

                                                }
                                        }
                                        else
                                        {
                                                if ((strcmp(Param[i-2], "&&") != 0) && (strcmp(Param[i-2], "||") != 0) && (strcmp(Param[i-2], ";") != 0))
                                                {
                                                        Command* left = CMD.top();
                                                        CMD.pop();
                                                        Operator* right = OP.top();
                                                        OP.push(new Semi(left, right));
                                                }
                                                else
                                                {
                                                        Operator* right = OP.top();
                                                        OP.pop();
                                                        Operator* left = OP.top();
							OP.push(right);
                                                        OP.push(new Semi(left, right));
                                                }
                                        }
                                }
				else
				{
					Parser* sub_parse = new Parser(Param[i]);
                                        vector<char*> newParam = sub_parse->ParseOperand();
                                        CMD.push(new Command(newParam));
				}
			}

			if (!OP.empty())
				OP.top()->evaluate();
			else
				CMD.top()->evaluate();

		}
	}
}
