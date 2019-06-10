#include "../header/ConstructTree.h"


ConstructTree::ConstructTree(vector<char*> param)
{
	Param = param;
	MakeTree();
}

void ConstructTree::MakeTree()
{
	bool checkRedirect = false;
	for(int i = 0; i < Param.size(); i++)
	{
		vector<char*> check_pipe_redirect;
		cout << Param[i] << endl;
		if(strcmp(Param[i] , "&&") == 0)
		{
			cout << "In And " << endl;
			if (CMD.empty())
			{
				cout << "In And CMD Empty" << endl;
				Operator* right = OP.top();
				OP.pop();
				Operator* left = OP.top();
				OP.push(right);
				OP.push(new Add(left, right));
			}
			else if ((strcmp(Param[i-1], "&&") != 0) && (strcmp(Param[i-1], "||") != 0) && (strcmp(Param[i-1], ";") != 0) && checkRedirect == false)
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
			else if (checkRedirect == true)
			{
				cout << "Hit" << endl;
				int size = check_pipe_redirect.size() - 1;
				if(CMD.empty() && OP.empty() && !RD.empty())
				{
					Redirect* right = RD.top();
					RD.pop();
					Redirect* left = RD.top();
					RD.pop();
					OP.push(new Add(left, right));
				}
				else if(CMD.empty() && !OP.empty() && !RD.empty() && (strcmp(check_pipe_redirect[size], "|") != 0))
				{
					Operator* left = OP.top();
					OP.pop();
					OP.push(new Add(left, RD.top()));
					RD.pop();
				}
				else if(CMD.empty() && !OP.empty() && !RD.empty() && (strcmp(check_pipe_redirect[size], "|") == 0))
				{
					Operator* right = OP.top();
					OP.pop();
					OP.push(new Add(RD.top(), right));
					RD.pop();
				}
				else if(!CMD.empty() && !RD.empty() && OP.empty() && ((string(Param[i-1]).find("<") == string::npos) || (string(Param[i-1]).find(">") == string::npos)))
				{
					OP.push(new Add(RD.top(), CMD.top()));
					RD.pop();
					CMD.pop();
				}
				else if(!CMD.empty() && !RD.empty() && OP.empty() && ((string(Param[i-1]).find("<") != string::npos) || (string(Param[i-1]).find(">") != string::npos)))
				{
					OP.push(new Add(CMD.top(), RD.top()));
					RD.pop();
					CMD.pop();
				}
				else if(!CMD.empty() && RD.empty() && !OP.empty() && (string(Param[i-1]).find("|") == string::npos))
				{
					Operator* left = OP.top();
					OP.pop();
					OP.push(new Add(left, CMD.top()));
					CMD.pop();
				}
				else if(!CMD.empty() && RD.empty() && !OP.empty() && (string(Param[i-1]).find("|") != string::npos))
				{
					Operator* right = OP.top();
					OP.pop();
					OP.push(new Add(CMD.top(), right));
					CMD.pop();
				}
				else if(CMD.empty() && RD.empty() && !OP.empty())
				{
					Operator* right = OP.top();
					OP.pop();
					Operator* left = OP.top();
					OP.pop();
					OP.push(new Add(left, right));
				}
				else;
				checkRedirect = false;
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
			else if ((strcmp(Param[i-1], "&&") != 0) && (strcmp(Param[i-1], "||") != 0) && (strcmp(Param[i-1], ";") != 0) && checkRedirect == false)
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
			else if (checkRedirect == true)
			{
				cout << "Hit" << endl;
				int size = check_pipe_redirect.size() - 1;
				if(CMD.empty() && OP.empty() && !RD.empty())
				{
					Redirect* right = RD.top();
					RD.pop();
					Redirect* left = RD.top();
					RD.pop();
					OP.push(new Or(left, right));
				}
				else if(CMD.empty() && !OP.empty() && !RD.empty() && (strcmp(check_pipe_redirect[size], "|") != 0))
				{
					Operator* left = OP.top();
					OP.pop();
					OP.push(new Or(left, RD.top()));
					RD.pop();
				}
				else if(CMD.empty() && !OP.empty() && !RD.empty() && (strcmp(check_pipe_redirect[size], "|") == 0))
				{
					Operator* right = OP.top();
					OP.pop();
					OP.push(new Or(RD.top(), right));
					RD.pop();
				}
				else if(!CMD.empty() && !RD.empty() && OP.empty() && ((string(Param[i-1]).find("<") == string::npos) || (string(Param[i-1]).find(">") == string::npos)))
				{
					OP.push(new Or(RD.top(), CMD.top()));
					RD.pop();
					CMD.pop();
				}
				else if(!CMD.empty() && !RD.empty() && OP.empty() && ((string(Param[i-1]).find("<") != string::npos) || (string(Param[i-1]).find(">") != string::npos)))
				{
					OP.push(new Or(CMD.top(), RD.top()));
					RD.pop();
					CMD.pop();
				}
				else if(!CMD.empty() && RD.empty() && !OP.empty() && (string(Param[i-1]).find("|") == string::npos))
				{
					Operator* left = OP.top();
					OP.pop();
					OP.push(new Or(left, CMD.top()));
					CMD.pop();
				}
				else if(!CMD.empty() && RD.empty() && !OP.empty() && (string(Param[i-1]).find("|") != string::npos))
				{
					Operator* right = OP.top();
					OP.pop();
					OP.push(new Or(CMD.top(), right));
					CMD.pop();
				}
				else if(CMD.empty() && RD.empty() && !OP.empty())
				{
					Operator* right = OP.top();
					OP.pop();
					Operator* left = OP.top();
					OP.pop();
					OP.push(new Or(left, right));
				}
				else;
				checkRedirect = false;
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
			else if ((strcmp(Param[i-1], "&&") != 0) && (strcmp(Param[i-1], "||") != 0) && (strcmp(Param[i-1], ";") != 0) && checkRedirect == false)
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
			else if (checkRedirect == true)
			{
				cout << "Hit" << endl;
				int size = check_pipe_redirect.size() - 1;
				if(CMD.empty() && OP.empty() && !RD.empty())
				{
					Redirect* right = RD.top();
					RD.pop();
					Redirect* left = RD.top();
					RD.pop();
					OP.push(new Semi(left, right));
				}
				else if(CMD.empty() && !OP.empty() && !RD.empty() && (strcmp(check_pipe_redirect[size], "|") != 0))
				{
					Operator* left = OP.top();
					OP.pop();
					OP.push(new Semi(left, RD.top()));
					RD.pop();
				}
				else if(CMD.empty() && !OP.empty() && !RD.empty() && (strcmp(check_pipe_redirect[size], "|") == 0))
				{
					Operator* right = OP.top();
					OP.pop();
					OP.push(new Semi(RD.top(), right));
					RD.pop();
				}
				else if(!CMD.empty() && !RD.empty() && OP.empty() && ((string(Param[i-1]).find("<") == string::npos) || (string(Param[i-1]).find(">") == string::npos)))
				{
					OP.push(new Semi(RD.top(), CMD.top()));
					RD.pop();
					CMD.pop();
				}
				else if(!CMD.empty() && !RD.empty() && OP.empty() && ((string(Param[i-1]).find("<") != string::npos) || (string(Param[i-1]).find(">") != string::npos)))
				{
					OP.push(new Semi(CMD.top(), RD.top()));
					RD.pop();
					CMD.pop();
				}
				else if(!CMD.empty() && RD.empty() && !OP.empty() && (string(Param[i-1]).find("|") == string::npos))
				{
					Operator* left = OP.top();
					OP.pop();
					OP.push(new Semi(left, CMD.top()));
					CMD.pop();
				}
				else if(!CMD.empty() && RD.empty() && !OP.empty() && (string(Param[i-1]).find("|") != string::npos))
				{
					Operator* right = OP.top();
					OP.pop();
					OP.push(new Semi(CMD.top(), right));
					CMD.pop();
				}
				else if(CMD.empty() && RD.empty() && !OP.empty())
				{
					Operator* right = OP.top();
					OP.pop();
					Operator* left = OP.top();
					OP.pop();
					OP.push(new Semi(left, right));
				}
				else;
				checkRedirect = false;
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
			check_pipe_redirect = sub_parse->ParsePipeRedirect();
			if(check_pipe_redirect.size() > 1)
			{
				checkRedirect = true;
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
						else if((k > 2) && ((strcmp(check_pipe_redirect[k-2], "<") == 0) || (strcmp(check_pipe_redirect[k-2], ">") == 0) || (strcmp(check_pipe_redirect[k-2], ">>") == 0)))
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
						else if((k > 2) && ((strcmp(check_pipe_redirect[k-2], "<") == 0) || (strcmp(check_pipe_redirect[k-2], ">") == 0) || (strcmp(check_pipe_redirect[k-2], ">>") == 0)))
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
						else if((k > 2) && ((strcmp(check_pipe_redirect[k-2], "<") == 0) || (strcmp(check_pipe_redirect[k-2], ">") == 0) || (strcmp(check_pipe_redirect[k-2], ">>") == 0)))
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
						if ((k > 2) && (strcmp(check_pipe_redirect[k-2], "|") == 0))
						{
							Operator* temp = OP.top();
							OP.pop();
							OP.push(new Pipe(temp, CMD.top()));
							CMD.pop();
						}
						else if((k > 2) && ((strcmp(check_pipe_redirect[k-2], "<") == 0) || (strcmp(check_pipe_redirect[k-2], ">") == 0) || (strcmp(check_pipe_redirect[k-2], ">>") == 0)))
						{
							OP.push(new Pipe(RD.top(), CMD.top()));
							CMD.pop();
							RD.pop();
						}
						else
						{
							Command* right = CMD.top();
							CMD.pop();
							Command* left = CMD.top();
							CMD.pop();
							OP.push(new Pipe(left, right));
						}
					}
					else
					{
						if ((strcmp(check_pipe_redirect[k+1], "<") == 0) || (strcmp(check_pipe_redirect[k+1], ">") == 0) || (strcmp(check_pipe_redirect[k+1], ">>") == 0));
							
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
