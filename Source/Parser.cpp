#include "../header/Parser.h"
#include <bits/stdc++.h>

Parser::Parser(string input)
{
	Input = (char*)input.c_str();
}

Parser::Parser(char* input)
{
	Input = input;
}

vector<char*> Parser::Parse1()
{
	vector<char*> Tokens;
	char temp[999];
	temp[0] = '\0';
	for(int i = 0; Input[i] != '\0'; i++)
	{
		switch(Input[i])
		{
			case ';':
                                {
                                        if (strlen(temp) > 0)
                                                Tokens.push_back(strdup(temp));
                                        Tokens.push_back(strndup(&Input[i], 1));
                                        temp[0] = '\0';
                                }
                                break;
                        case '&':
                                {
                                        if(Input[i+1] == '&')
                                        {
                                                if(strlen(temp) > 0)
                                                        Tokens.push_back(strdup(temp));
                                                Tokens.push_back(strndup(&Input[i], 2));
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
                                                Tokens.push_back(strndup(&Input[i], 2));
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
        for(int i = 0; i < Tokens.size(); ++i)
        {
                if ((strcmp(Tokens[i], "&&") == 0) || (strcmp(Tokens[i], "||") == 0) || (strcmp(Tokens[i], ";") == 0))
		{
			swap(Tokens[i], Tokens[i+1]);
			i++;
		}
        }
	return Tokens;
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
