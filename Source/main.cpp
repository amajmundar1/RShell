#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <unistd.h>
#include "../header/Parser.h"
#include "../header/Command.h"
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
		else 
		{
			Parser* pars = new Parser(input);
			vector<char*> Param = pars->Parse1();
			for(int i = 0; i < Param.size(); i++)
				cout << Param[i] << endl;
			vector<Command*> CMD;
			vector<Add*> ADD;
			vector<Semi*> SEMI;
			vector<Or*> OR;
			/*
			for(int i = 0; i < Param.size(); i++)
			{
				switch Param[i]
				{
					case "&&":
						{
							switch Param[i-2]
							{
								case "&&":
									{
										ADD.push_back(new Add(ADD[ADD.size()-1], CMD[CMD.size()-1]));
									}
									break;
								case "||":
									{
										ADD.push_back(new Add(OR[OR.size()-1], CMD[CMD.size()-1]));
									}
									break;
								case ";":
									{
										ADD.push_back(new Add(SEMI[OR.size()-1], CMD[CMD.size()-1]));
									}
									break;
								default:
									{
										ADD.push_back(new Add(CMD[CMD.size()-1], CMD[CMD.size()-2]));
									}
									break;
							}
						}
						break;
					case "||":
						{
							switch Param[i-2]
                                                        {
                                                                case "&&":
                                                                        {
                                                                                OR.push_back(new Or(ADD[ADD.size()-1], CMD[CMD.size()-1]));
                                                                        }
                                                                        break;
                                                                case "||":
                                                                        {
                                                                                OR.push_back(new Or(OR[OR.size()-1], CMD[CMD.size()-1]));
                                                                        }
                                                                        break;
                                                                case ";":
                                                                        {
                                                                                OR.push_back(new Or(SEMI[OR.size()-1], CMD[CMD.size()-1]));
                                                                        }
                                                                        break;
                                                                default:
                                                                        {
                                                                                OR.push_back(new Or(CMD[CMD.size()-1], CMD[CMD.size()-2]));
                                                                        }
                                                                        break;
							}
						}
						break;
					case ";":
						{
							 switch Param[i-2]
                                                        {
                                                                case "&&":
                                                                        {
                                                                                SEMI.push_back(new Semi(ADD[ADD.size()-1], CMD[CMD.size()-1]));
                                                                        }
                                                                        break;
                                                                case "||":
                                                                        {
                                                                                SEMI.push_back(new Semi(OR[OR.size()-1], CMD[CMD.size()-1]));
                                                                        }
                                                                        break;
                                                                case ";":
                                                                        {
                                                                                SEMI.push_back(new Semi(SEMI[OR.size()-1], CMD[CMD.size()-1]));
                                                                        }
                                                                        break;
                                                                default:
                                                                        {
                                                                                SEMI.push_back(new Semi(CMD[CMD.size()-1], CMD[CMD.size()-2]));
                                                                        }
                                                                        break;
							}
						}
						break;
					default:
						{
							Parser* sub_parse = new Parser(Param[i]);
							vector<char*> newParam = sub_parse->Parse();
							CMD.push_back(new CMD(newParam));
						}
						break;
				}
			}
		*/
		}

	}
}
