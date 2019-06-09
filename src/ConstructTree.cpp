#include "../header/ConstructTree.h"


ConstructTree::ConstructTree(vector<char*> param)
{
	Param = param;
	MakeTree();
}

void ConstructTree::MakeTree()
{
	for(int i = 0; i < Param.size(); i++)
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
			vector<char*> check_pipe_redirect = sub_parse->ParsePipeRedirect();
			if(check_pipe_redirect.size() > 1)
			{
				for(int k = 0; k < check_pipe_redirect.size(); k++)
				{
					cout << check_pipe_redirect[k] << endl;
					if(strcmp(check_pipe_redirect[k], "<") == 0)
					{
						if ((k > 2) && (strcmp(check_pipe_redirect[k-2], "|") == 0))
						{
							RD.push(new RedirectInput(OP.top(), check_pipe_redirect[k-1]));
							OP.pop();
						}
						else if ((k > 2) && ((strcmp(check_pipe_redirect[k-2], "<") == 0) || (strcmp(check_pipe_redirect[k-2], ">") == 0) || (strcmp(check_pipe_redirect[k-2], ">>") == 0)))
						{
							Redirect* temp = new RedirectInput(RD.top(), check_pipe_redirect[k-1]);
							RD.pop();
							RD.push(temp);
						}
						else
						{
							RD.push(new RedirectInput(CMD.top(), check_pipe_redirect[k-1]));
							CMD.pop();
						}
					}
					else if (strcmp(check_pipe_redirect[k], ">") == 0)
					{
						if ((k > 2) && (strcmp(check_pipe_redirect[k-2], "|") == 0))
						{
							RD.push(new RedirectOutput(OP.top(), check_pipe_redirect[k-1]));
							OP.pop();
						}
						else if ((k > 2) && ((strcmp(check_pipe_redirect[k-2], "<") == 0) || (strcmp(check_pipe_redirect[k-2], ">") == 0) || (strcmp(check_pipe_redirect[k-2], ">>") == 0)))
						{
							Redirect* temp = new RedirectOutput(RD.top(), check_pipe_redirect[k-1]);
							RD.pop();
							RD.push(temp);
						}
						else
						{
							RD.push(new RedirectOutput(CMD.top(), check_pipe_redirect[k-1]));
							CMD.pop();
						}
					}
					else if (strcmp(check_pipe_redirect[k], ">>") == 0)
					{
						if ((k > 2) && (strcmp(check_pipe_redirect[k-2], "|") == 0))
						{
							RD.push(new AppendOutput(OP.top(), check_pipe_redirect[k-1]));
							OP.pop();
						}
						else if ((k > 2) && ((strcmp(check_pipe_redirect[k-2], "<") == 0) || (strcmp(check_pipe_redirect[k-2], ">") == 0) || (strcmp(check_pipe_redirect[k-2], ">>") == 0)))
						{
							Redirect* temp = new AppendOutput(RD.top(), check_pipe_redirect[k-1]);
							RD.pop();
							RD.push(temp);
						}
						else
						{
							RD.push(new AppendOutput(CMD.top(), check_pipe_redirect[k-1]));
							CMD.pop();
						}
					}
					else if (strcmp(check_pipe_redirect[k], "|") == 0)
					{
						cout << "Inside Pipe" << endl;
						if ((k > 2) && (strcmp(check_pipe_redirect[k-2], "|") == 0))
						{
							OP.push(new Pipe(OP.top(), CMD.top()));
							OP.pop();
							CMD.pop();
						}
						else if ((k > 2) && ((strcmp(check_pipe_redirect[k-2], "<") == 0) || (strcmp(check_pipe_redirect[k-2], ">") == 0) || (strcmp(check_pipe_redirect[k-2], ">>") == 0)))
						{
							OP.push(new Pipe(RD.top(), CMD.top()));
							CMD.pop();
							RD.pop();
						}
						else
						{
							cout << "Inside else pipe" << endl;
							Command* right = CMD.top();
							CMD.pop();
							Command* left = CMD.top();
							CMD.pop();
							OP.push(new Pipe(left, right));
						}
					}
					else
					{
						if ((strcmp(check_pipe_redirect[k+1], "<") == 0) || (strcmp(check_pipe_redirect[k+1], ">") == 0) || (strcmp(check_pipe_redirect[k+1], ">>") == 0))
							k++;
						else
						{
							Parser* newParser1 = new Parser(check_pipe_redirect[k]);
							vector<char*> newParam1 = newParser1->ParseOperand();
							CMD.push(new Command(newParam1));
						}
					}
				}
			}
			else
			{
                        	vector<char*> newParam = sub_parse->ParseOperand();
                        	CMD.push(new Command(newParam));
			}
		}
	}
}

stack<Command*> ConstructTree::getCommands()
{
	return CMD;
}

stack<Operator*> ConstructTree::getOperators()
{
	return OP;
}

stack<Redirect*> ConstructTree::getRedirect()
{
	return RD;
}
