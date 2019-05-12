#include "Parser.h"
#include <bits/stdc++.h>

Parser::Parser(char *input)
{
	Input = input;
}

vector<char*> Parser::Parse()
{
	vector<char*> tokens;
	char temp[999];
	char* t;
	int i = 0;
	for(t = Input; *t != '\0'; t++)
	{
		switch(t[i])
		{
			case ' ':
				{
			       		tokens.push_back(temp);
				}
				break;
			case '"':
				{
					bool found = false;
					while (found != true)
					{
						i += 1;
						if (t[i] == '"')
							found = true;
						else
							strncat(temp, &t[i], 1);
					}
				}
				break;
			default:
				{
					strncat(temp, &t[i], 1);
				}
				break;
		}
		i += 1;
	}
	return tokens;
}
