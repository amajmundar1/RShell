#include "Parser.h"
#include <bits/stdc++.h>

Parser::Parser(string input)
{
	Input = (char*)input.c_str();
	Parse();
}

void Parser::Parse()
{
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
					cout << temp << endl;
					temp[0] = '\0';
				}
				break;
			case '"':
				{
					bool found = false;
					while (found != true)
					{
						i += 1;
						if (Input[i] == '"')
							found = true;
						else
							strncat(temp, &Input[i], 1);
					}
				}
				break;
			case ';':
				{
					if (strlen(temp) > 0)
						Tokens.push_back(strdup(temp));
					Tokens.push_back(strdup(&Input[i]));
					temp[0] = '\0';
				}
				break;
			case '&':
				{
					if(Input[i+1] == '&')
					{
						if(strlen(temp) > 0)
							Tokens.push_back(strdup(temp));
						Tokens.push_back(strdup(&Input[i]));
						temp[0] = '\0';
						i++;
					}
					else
						strncat(temp, &Input[i], 1);
				}
				break;
			case '|':
				{
					if(Input[i+1] == '|')
					{
						if (strlen(temp) > 0)
							Tokens.push_back(strdup(temp));
						Tokens.push_back(strdup(&Input[i]));
						temp[0] = '\0';
						i++;
					}
					else
						strncat(temp, &Input[i], 1);
				}
				break;
			default:
				{
					strncat(temp, &Input[i], 1);
				}
				break;
		}
	}
}

char** Parser::getParse()
{
	char ** Output = new char* [Tokens.size()];
	for(int i = 0; i < Tokens.size(); i++)
		Output[i] = Tokens[i];
	//Output[Token.size()+1] = '\0';
	//const char* file = Tokens[0];
	//return make_tuple(file, Output);
	return Output;
}

int Parser::getSize()
{
	return Tokens.size();
}
