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
#include "../header/Test.h"
#include "../header/ConstructTree.h"
#include "../header/Redirect.h"
//#include "../header/Pipe.h"


using namespace std;

TEST(SingleCommand, Echo) {
	string input = "echo test";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(0,1), true);

	string input1 = "echo hello";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(0,1), true);
}

TEST(SingleCommand, ls) {
	string input = "ls";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(0,1), true);

	string input1 = "ls -a";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(0,1), true);

	string input2 = "ls -l";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->ParseOperator();
	ConstructTree* BuildTree2 = new ConstructTree(Input2);
	stack<Command*> CMD2 = BuildTree2->getCommands();
	stack<Operator*> OP2 = BuildTree2->getOperators();
	if (!OP2.empty())
		EXPECT_EQ(OP2.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD2.top()->evaluate(0,1), true);
}

TEST(SingleCommand, Make_and_Remove) {
	string input = "mkdir deleteThis";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(0,1), true);

	string input1 = "rm -r deleteThis";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(0,1), true);
}

TEST(SingleCommand, cat) {
	string input = "cat src/Add.cpp";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(0,1), true);
}

TEST(SingleCommand, ps) {
	string input = "ps";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(0,1), true);
}

TEST(MultCommand, And) {
	string input = "echo A && echo B";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(0,1), true);

	string input1 = "ls && ps";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(0,1), true);

	string input2 = "cat fakeFile && echo C";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->ParseOperator();
	ConstructTree* BuildTree2 = new ConstructTree(Input2);
	stack<Command*> CMD2 = BuildTree2->getCommands();
	stack<Operator*> OP2 = BuildTree2->getOperators();
	if (!OP2.empty())
		EXPECT_EQ(OP2.top()->evaluate(0,1), false);
	else
		EXPECT_EQ(CMD2.top()->evaluate(0,1), false);

}

TEST(MultCommand, Or) {
	string input = "echo A || echo wrong output";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(0,1), true);

	string input1 = "ls || echo hello";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(0,1), true);

	string input2 = "cat fakeFile || echo B";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->ParseOperator();
	ConstructTree* BuildTree2 = new ConstructTree(Input2);
	stack<Command*> CMD2 = BuildTree2->getCommands();
	stack<Operator*> OP2 = BuildTree2->getOperators();
	if (!OP2.empty())
		EXPECT_EQ(OP2.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD2.top()->evaluate(0,1), true);
}

TEST(MultCommand, Semi) {
	string input = "echo A; echo B";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(0,1), true);

	string input1 = "ls; ps";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(0,1), true);

	string input2 = "cat fakeFile; echo C; ls;";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->ParseOperator();
	ConstructTree* BuildTree2 = new ConstructTree(Input2);
	stack<Command*> CMD2 = BuildTree2->getCommands();
	stack<Operator*> OP2 = BuildTree2->getOperators();
	if (!OP2.empty())
		EXPECT_EQ(OP2.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD2.top()->evaluate(0,1), true);
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
			EXPECT_EQ(OP.top()->evaluate(0,1), true);
		else
			EXPECT_EQ(CMD.top()->evaluate(0,1), true);
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
			EXPECT_EQ(OP1.top()->evaluate(0,1), true);
		else
			EXPECT_EQ(CMD1.top()->evaluate(0,1), true);
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
			EXPECT_EQ(OP2.top()->evaluate(0,1), true);
		else
			EXPECT_EQ(CMD2.top()->evaluate(0,1), true);
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
		EXPECT_EQ(OP.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(0,1), true);

	string input1 = "ls; ps && echo C";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(0,1), true);

	string input2 = "cat file || echo \"file does not exist\" && echo D; ls || ls -r";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->ParseOperator();
	ConstructTree* BuildTree2 = new ConstructTree(Input2);
	stack<Command*> CMD2 = BuildTree2->getCommands();
	stack<Operator*> OP2 = BuildTree2->getOperators();
	if (!OP2.empty())
		EXPECT_EQ(OP2.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD2.top()->evaluate(0,1), true);
}

TEST(MultCommand, parentheses) {
	string input = "(echo A && echo B) || (ls -a && echo C)";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
	ConstructTree* BuildTree = new ConstructTree(Input);
	stack<Command*> CMD = BuildTree->getCommands();
	stack<Operator*> OP = BuildTree->getOperators();
	if (!OP.empty())
		EXPECT_EQ(OP.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD.top()->evaluate(0,1), true);

	string input1 = "(echo D; ls) && (mkdir temp && rm -r temp)";
	Parser* parse1 = new Parser(input1);
	vector<char*> Input1 = parse1->ParseOperator();
	ConstructTree* BuildTree1 = new ConstructTree(Input1);
	stack<Command*> CMD1 = BuildTree1->getCommands();
	stack<Operator*> OP1 = BuildTree1->getOperators();
	if (!OP1.empty())
		EXPECT_EQ(OP1.top()->evaluate(0,1), true);
	else
		EXPECT_EQ(CMD1.top()->evaluate(0,1), true);
}

TEST(SingleCommandTestSet, test1) 
{
	string input = "test src/Add.cpp";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
        ConstructTree* BuildTree = new ConstructTree(Input);
        stack<Command*> CMD = BuildTree->getCommands();
        stack<Operator*> OP = BuildTree->getOperators();
        if (!OP.empty())
                EXPECT_EQ(OP.top()->evaluate(0,1), true);
        else
                EXPECT_EQ(CMD.top()->evaluate(0,1), true);
}
TEST(SingleCommandTestSet, test2)
{
	string input = "test -e src/Or.cpp";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
        ConstructTree* BuildTree = new ConstructTree(Input);
        stack<Command*> CMD = BuildTree->getCommands();
        stack<Operator*> OP = BuildTree->getOperators();
        if (!OP.empty())
                EXPECT_EQ(OP.top()->evaluate(0,1), true);
        else
                EXPECT_EQ(CMD.top()->evaluate(0,1), true);
}
TEST(SingleCommandTestSet, test3)
{
	string input3 = "test -f integration_tests/exit_command_tests.sh";
	Parser* parse3 = new Parser(input3);
	vector<char*> Input3 = parse3->ParseOperator();
        ConstructTree* BuildTree3 = new ConstructTree(Input3);
        stack<Command*> CMD3 = BuildTree3->getCommands();
        stack<Operator*> OP3 = BuildTree3->getOperators();
        if (!OP3.empty())
                EXPECT_EQ(OP3.top()->evaluate(0,1), true);
        else
                EXPECT_EQ(CMD3.top()->evaluate(0,1), true);
}
TEST(SingleCommandTestSet, test4)
{
	string input = "test -d header/";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->ParseOperator();
        ConstructTree* BuildTree = new ConstructTree(Input);
        stack<Command*> CMD = BuildTree->getCommands();
        stack<Operator*> OP = BuildTree->getOperators();
        if (!OP.empty())
                EXPECT_EQ(OP.top()->evaluate(0,1), true);
        else
                EXPECT_EQ(CMD.top()->evaluate(0,1), true);
}

TEST(SingleCommandTestSet, Pipe)
{
        string input = "cat names.txt | wc";
        Parser* parse = new Parser(input);
        vector<char*> Input = parse->ParseOperator();
        ConstructTree* BuildTree = new ConstructTree(Input);
        stack<Command*> CMD = BuildTree->getCommands();
        stack<Operator*> OP = BuildTree->getOperators();
        if (!OP.empty())
                EXPECT_EQ(OP.top()->evaluate(0, 1), true);
        else
                EXPECT_EQ(CMD.top()->evaluate(0, 1), true);
}

TEST(SingleCommandTestSet, RedirectInput) {
        string input = "grep a < names.txt";
        Parser* parse = new Parser(input);
        vector<char*> Input = parse->ParseOperator();
        ConstructTree* BuildTree = new ConstructTree(Input);
        stack<Command*> CMD = BuildTree->getCommands();
        stack<Operator*> OP = BuildTree->getOperators();
	stack<Redirect*> RD = BuildTree->getRedirect();
        if (!OP.empty())
                EXPECT_EQ(OP.top()->evaluate(0, 1), true);
	else if(!RD.empty())
		EXPECT_EQ(RD.top()->evaluate(0,1), true);
        else
                EXPECT_EQ(CMD.top()->evaluate(0, 1), true);
}

TEST(SingleCommandTestSet, RedirectOutput) {
        string input = "ls > temp.cpp";
        Parser* parse = new Parser(input);
        vector<char*> Input = parse->ParseOperator();
        ConstructTree* BuildTree = new ConstructTree(Input);
        stack<Command*> CMD = BuildTree->getCommands();
        stack<Operator*> OP = BuildTree->getOperators();
	stack<Redirect*> RD = BuildTree->getRedirect();
        if (!OP.empty())
                EXPECT_EQ(OP.top()->evaluate(0, 1), true);
	else if(!RD.empty())
		EXPECT_EQ(RD.top()->evaluate(0,1), true);
        else
                EXPECT_EQ(CMD.top()->evaluate(0, 1), true);
	
        string input1 = "ls -r >> temp.cpp";
        Parser* parse1 = new Parser(input1);
        vector<char*> Input1 = parse1->ParseOperator();
        ConstructTree* BuildTree1 = new ConstructTree(Input1);
        stack<Command*> CMD1 = BuildTree1->getCommands();
        stack<Operator*> OP1 = BuildTree1->getOperators();
	stack<Redirect*> RD1 = BuildTree->getRedirect();
        if (!OP1.empty())
                EXPECT_EQ(OP1.top()->evaluate(0, 1), true);
	else if(!RD1.empty())
		EXPECT_EQ(RD1.top()->evaluate(0,1), true);
        else
                EXPECT_EQ(CMD1.top()->evaluate(0, 1), true);
}

TEST(MultCommandTestSet, Example4)
{
	string input = "echo abcdefghijklmnopqrstuvwxyz | tr A-Z a-z | tee newOutputFile1.h | tr a-z A-Z > newOutputFile2.h";
        Parser* parse = new Parser(input);
        vector<char*> Input = parse->ParseOperator();
        ConstructTree* BuildTree = new ConstructTree(Input);
        stack<Command*> CMD = BuildTree->getCommands();
        stack<Operator*> OP = BuildTree->getOperators();
	stack<Redirect*> RD = BuildTree->getRedirect();
        if (!OP.empty())
                EXPECT_EQ(OP.top()->evaluate(0, 1), true);
	else if(!RD.empty())
		EXPECT_EQ(RD.top()->evaluate(0,1), true);
        else
                EXPECT_EQ(CMD.top()->evaluate(0, 1), true);
}

TEST(MultCommandTestSet, RedirectParen)
{
	string input = "(la || ls) && cat < old.txt";
        Parser* parse = new Parser(input);
        vector<char*> Input = parse->ParseOperator();
        ConstructTree* BuildTree = new ConstructTree(Input);
        stack<Command*> CMD = BuildTree->getCommands();
        stack<Operator*> OP = BuildTree->getOperators();
	stack<Redirect*> RD = BuildTree->getRedirect();
        if (!OP.empty())
                EXPECT_EQ(OP.top()->evaluate(0, 1), true);
	else if(!RD.empty())
		EXPECT_EQ(RD.top()->evaluate(0,1), true);
        else
                EXPECT_EQ(CMD.top()->evaluate(0, 1), true);
}

int main(int argc, char **argv) {
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}
