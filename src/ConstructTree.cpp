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
			//cout << Param[i] << endl;
			Parser* sub_parse = new Parser(Param[i]);
                        vector<char*> newParam = sub_parse->ParseOperand();
			//for(int j = 0; j < newParam.size(); j++)
			//	cout << newParam[j] << endl;
                        CMD.push(new Command(newParam));
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
