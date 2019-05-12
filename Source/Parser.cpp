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
	temp[0] = '\0';
	for(int i = 0; Input[i] != '\0'; i++)
	{
		switch(Input[i])
		{
			case ' ':
				{
					if (strlen(temp) > 0)
			       			tokens.push_back(strdup(temp));
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
			default:
				{
					strncat(temp, &Input[i], 1);
				}
				break;
		}
	}
	return tokens;
}
