#include "../header/Parser.h"
#include <bits/stdc++.h>

Parser::Parser(string input)
{
	Input = (char*)input.c_str();
}

vector<char*> Parser::Parse()
{
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
	if (strlen(temp) > 0)
		Tokens.push_back(strdup(temp));
	return Tokens;
}


