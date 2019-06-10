#include "../header/Parser.h"
#include <bits/stdc++.h>
#include <stack>

Parser::Parser(string input)
{
	Input = (char*)input.c_str();
}

Parser::Parser(char* input)
{
	Input = input;
}

vector<char*> Parser::ParseOperator()
{
	stack<char*> Stack;
	vector<char*> Tokens;
	char temp[999];
	temp[0] = '\0';
	for(int i = 0; Input[i] != '\0'; i++)
	{
		switch(Input[i])
		{
			case '(':
				{
					Stack.push(strndup(&Input[i], 1));
				}
				break;
			case ')':
				{
					if (strlen(temp) > 0)
						Tokens.push_back(strdup(temp));
					temp[0] = '\0';
					while (strcmp(Stack.top(), "(") != 0)
					{
						Tokens.push_back(Stack.top());
						Stack.pop();
					}
					Stack.pop();
					if(Input[i+1] == ' ')
						i++;
				}
				break;
			case ';':
                                {
                                        if (strlen(temp) > 0)
                                                Tokens.push_back(strdup(temp));
					if (!Stack.empty())
					{
						if ((strcmp(Stack.top(), "||") == 0) || (strcmp(Stack.top(), "&&") == 0) || (strcmp(Stack.top(), ";") == 0))
						{
							Tokens.push_back(Stack.top());
							Stack.pop();
						}
					}
                                        Stack.push(strndup(&Input[i], 1));
                                        temp[0] = '\0';
					if(Input[i+1] == ' ')
                                                i++;
                                }
                                break;
                        case '&':
                                {
                                        if(Input[i+1] == '&')
                                        {
                                                if(strlen(temp) > 0)
                                                        Tokens.push_back(strdup(temp));
						if (!Stack.empty())
						{
							if ((strcmp(Stack.top(), "||") == 0) || (strcmp(Stack.top(), "&&") == 0) || (strcmp(Stack.top(), ";") == 0))
							{
								Tokens.push_back(Stack.top());
								Stack.pop();
							}
						}
                                                Stack.push(strndup(&Input[i], 2));
                                                temp[0] = '\0';
                                                i++;
                                        }
                                        else
                                                strncat(temp, &Input[i], 1);
					if(Input[i+1] == ' ')
                                                i++;
                                }
                                break;
                        case '|':
                                {
                                        if(Input[i+1] == '|')
                                        {
                                                if (strlen(temp) > 0)
                                                        Tokens.push_back(strdup(temp));
						if (!Stack.empty())
						{
							if ((strcmp(Stack.top(), "||") == 0) || (strcmp(Stack.top(), "&&") == 0) || (strcmp(Stack.top(), ";") == 0))
							{
								Tokens.push_back(Stack.top());
								Stack.pop();
							}
						}
                                                Stack.push(strndup(&Input[i], 2));
                                                temp[0] = '\0';
                                                i++;
						if(Input[i+1] == ' ')
                                                	i++;
                                        }
                                        else
                                                strncat(temp, &Input[i], 1);
                                }
                                break;
			case '#':
				{
					if (strlen(temp) > 0)
						Tokens.push_back(strdup(temp));
					i = strlen(Input)-1;
				}
				break;
			default:
				{
                                        strncat(temp, &Input[i], 1);
                                }
                                break;
		}
	}
	if (strlen(temp) > 0)
                Tokens.push_back(strdup(temp));
	while (!Stack.empty())
	{
		Tokens.push_back(Stack.top());
		Stack.pop();
	}
	return Tokens;
}


vector<char*> Parser::ParseOperand()
{
	stack<char*> Stack;
	vector<char*> Tokens;
	char temp[999];
	temp[0] = '\0';
	for(int i = 0; Input[i] != '\0'; i++)
	{
		switch(Input[i])
		{
			case ' ':
				{
					if (strlen(temp) > 0)
			       			Tokens.push_back(strdup(temp));
					temp[0] = '\0';
				}
				break;
			case '"':
				{
					int j = i+1;
					while (Input[j] != '"')
					{
						strncat(temp, &Input[j], 1);
						j++;
					}
					Tokens.push_back(strdup(temp));
					temp[0] = '\0';
					i = j++;
				}
				break;
			default:
				{
					strncat(temp, &Input[i], 1);
				}
				break;
		}
	}
	if (strlen(temp) > 0)
		Tokens.push_back(strdup(temp));
	return Tokens;
}

vector<char*> Parser::ParsePipeRedirect()
{
	stack<char*> Stack;
	vector<char*> Tokens;
	char temp[999];
	temp[0] = '\0';
	for(int i = 0; Input[i] != '\0'; i++)
	{
		switch(Input[i])
		{
			case '|':
				{
					if(strlen(temp) > 0)
						Tokens.push_back(strdup(temp));
					temp[0] = '\0';
					if (!Stack.empty())
					{
						if ((strcmp(Stack.top(), "|") == 0) || (strcmp(Stack.top(), "<") == 0) || (strcmp(Stack.top(), ">") == 0) || (strcmp(Stack.top(), ">>") == 0))
						{
							Tokens.push_back(Stack.top());
							Stack.pop();
						}
					}
					Stack.push(strndup(&Input[i], 1));
					if(Input[i+1] == ' ')
						i++;
				}
				break;
			case '<':
				{
					if (strlen(temp) > 0)
						Tokens.push_back(strdup(temp));
					temp[0] = '\0';
					if (!Stack.empty())
					{
						if ((strcmp(Stack.top(), "|") == 0) || (strcmp(Stack.top(), "<") == 0) || (strcmp(Stack.top(), ">") == 0) || (strcmp(Stack.top(), ">>") == 0))
						{
							Tokens.push_back(Stack.top());
							Stack.pop();
						}
					}
					Stack.push(strndup(&Input[i], 1));
					if(Input[i+1] == ' ')
						i++;
				}
				break;
			case '>':
				{
					if (strlen(temp) > 0)
						Tokens.push_back(strdup(temp));
					temp[0] = '\0';
					if (!Stack.empty())
					{
						if ((strcmp(Stack.top(), "|") == 0) || (strcmp(Stack.top(), "<") == 0) || (strcmp(Stack.top(), ">") == 0) || (strcmp(Stack.top(), ">>") == 0))
						{
							Tokens.push_back(Stack.top());
							Stack.pop();
						}
					}
					if (Input[i+1] == '>')
					{
						Stack.push(strndup(&Input[i], 2));
						i++;
					}
					else
						Stack.push(strndup(&Input[i], 1));
					if(Input[i+1] == ' ')
						i++;
				}
				break;
			default:
				{
					strncat(temp, &Input[i], 1);
				}
				break;
		}
	}
	if (strlen(temp) > 0)
		Tokens.push_back(strdup(temp));
	while (!Stack.empty())
	{
		Tokens.push_back(Stack.top());
		Stack.pop();
	}
	return Tokens;
}
