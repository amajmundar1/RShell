// Put the google tests here
#include "gtest/gtest.h"
//#include <string.h>
#include <vector>
#include <stack>

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <unistd.h>
#include "../header/Parser.h"
#include "../header/Command.h"
#include "../header/Operator.h"
#include "../header/Add.h"
#include "../header/Or.h"
#include "../header/Semi.h"
#include "../header/ConstructTree.h"
using namespace std;

TEST(SingleCommand, Echo) {
	string input = "echo test";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(), true);

	string input1 = "echo hello";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(), true);
}

TEST(SingleCommand, ls) {
	string input = "ls";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(), true);

	string input1 = "ls -a";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(), true);

	string input2 = "ls -l";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->ParseOperator();
	ConstructTree* BuildTree2 = new ConstructTree(Input2);
	stack<Command*> CMD2 = BuildTree2->getCommands();
	stack<Operator*> OP2 = BuildTree2->getOperators();
	if (!OP2.empty())
		EXPECT_EQ(OP2.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD2.top()->evaluate(), true);
}

TEST(SingleCommand, Make_and_Remove) {
	string input = "mkdir deleteThis";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(), true);

	string input1 = "rm -r deleteThis";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(), true);
}

TEST(SingleCommand, cat) {
	string input = "cat src/Add.cpp";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(), true);
}

TEST(SingleCommand, ps) {
	string input = "ps";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(), true);
}

TEST(MultCommand, And) {
	string input = "echo A && echo B";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(), true);

	string input1 = "ls && ps";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(), true);

	string input2 = "cat fakeFile && echo C";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->ParseOperator();
	ConstructTree* BuildTree2 = new ConstructTree(Input2);
	stack<Command*> CMD2 = BuildTree2->getCommands();
	stack<Operator*> OP2 = BuildTree2->getOperators();
	if (!OP2.empty())
		EXPECT_EQ(OP2.top()->evaluate(), false);
	else
		EXPECT_EQ(CMD2.top()->evaluate(), false);

}

TEST(MultCommand, Or) {
	string input = "echo A || echo wrong output";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(), true);

	string input1 = "ls || echo hello";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(), true);

	string input2 = "cat fakeFile || echo B";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->ParseOperator();
	ConstructTree* BuildTree2 = new ConstructTree(Input2);
	stack<Command*> CMD2 = BuildTree2->getCommands();
	stack<Operator*> OP2 = BuildTree2->getOperators();
	if (!OP2.empty())
		EXPECT_EQ(OP2.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD2.top()->evaluate(), true);
}

TEST(MultCommand, Semi) {
	string input = "echo A; echo B";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(), true);

	string input1 = "ls; ps";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(), true);

	string input2 = "cat fakeFile; echo C; ls;";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->ParseOperator();
	ConstructTree* BuildTree2 = new ConstructTree(Input2);
	stack<Command*> CMD2 = BuildTree2->getCommands();
	stack<Operator*> OP2 = BuildTree2->getOperators();
	if (!OP2.empty())
		EXPECT_EQ(OP2.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD2.top()->evaluate(), true);
}

TEST(MultCommand, Comment) {
	string input = "echo A # echo X";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	if(!Input.empty())
	{
		ConstructTree* BuildTree = new ConstructTree(Input);
		stack<Command*> CMD = BuildTree->getCommands();
		stack<Operator*> OP = BuildTree->getOperators();
		if (!OP.empty())
			EXPECT_EQ(OP.top()->evaluate(), true);
		else
			EXPECT_EQ(CMD.top()->evaluate(), true);
	}

	string input1 = "ls; ps && echo hello # comment";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	if(!Input1.empty())
	{
		ConstructTree* BuildTree1 = new ConstructTree(Input1);
		stack<Command*> CMD1 = BuildTree1->getCommands();
		stack<Operator*> OP1 = BuildTree1->getOperators();
		if (!OP1.empty())
			EXPECT_EQ(OP1.top()->evaluate(), true);
		else
			EXPECT_EQ(CMD1.top()->evaluate(), true);
	}

	string input2 = "ls -a #; ls -lR";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->ParseOperator();
	if(!Input2.empty())
	{
		ConstructTree* BuildTree2 = new ConstructTree(Input2);
		stack<Command*> CMD2 = BuildTree2->getCommands();
		stack<Operator*> OP2 = BuildTree2->getOperators();
		if (!OP2.empty())
			EXPECT_EQ(OP2.top()->evaluate(), true);
		else
			EXPECT_EQ(CMD2.top()->evaluate(), true);
	}
}

TEST(MultCommand, Combo) {
	string input = "echo A && echo B || ls";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(), true);

	string input1 = "ls; ps && echo C";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(), true);

	string input2 = "cat file || echo \"file does not exist\" && echo D; ls || ls -r";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->ParseOperator();
	ConstructTree* BuildTree2 = new ConstructTree(Input2);
	stack<Command*> CMD2 = BuildTree2->getCommands();
	stack<Operator*> OP2 = BuildTree2->getOperators();
	if (!OP2.empty())
		EXPECT_EQ(OP2.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD2.top()->evaluate(), true);
}

TEST(MultCommand, parentheses) {
	string input = "(echo A && echo B) || (ls -a && echo C)";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(), true);

	string input1 = "(echo D; ls) && (mkdir temp && rm -r temp)";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(), true);
}
/*
TEST(SingleCommand, test) {
	string input = "test /src/Add.cpp"
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
	string input2 = "test -e /src/Or.cpp";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->Parse();
	Command* cmd2 = new Command(Input2);
	EXPECT_EQ(cmd2->evaluate(), true);
	string input3 = "test -f /integration_tests/exit_command_test.sh";
	Parser* parse3 = new Parser(input3);
	vector<char*> Input3 = parse3->Parse();
	Command* cmd3 = new Command(Input3);
	EXPECT_EQ(cmd3->evaluate(), true);
	string input4 = "test -d /header/";
	Parser* parse4 = new Parser(input4);
	vector<char*> Input4 = parse4->Parse();
	Command* cmd4 = new Command(Input4);
	EXPECT_EQ(cmd4->evaluate(), true);
}
*/

int main(int argc, char **argv) {
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}
