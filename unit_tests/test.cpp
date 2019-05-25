// Put the google tests here
#include <iostream>
#include "../header/Add.h"
#include "../header/Or.h"
#include "../header/Semi.h"
#include "../header/Command.h"
#include "../header/Parser.h"
#include "gtest/gtest.h"
#include <string.h>
#include <unistd.h>
#include <vector>

using namespace std;

TEST(SingleCommand, Echo) {
	string input = "echo begin test";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
	string input2 = "echo hello";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->Parse();
	Command* cmd2 = new Command(Input2);
	EXPECT_EQ(cmd2->evaluate(), true);
}

TEST(SingleCommand, ls) {
	string input = "ls";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
	string input2 = "ls -a";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->Parse();
	Command* cmd2 = new Command(Input2);
	EXPECT_EQ(cmd2->evaluate(), true);
	string input3 = "ls -r";
	Parser* parse3 = new Parser(input3);
	vector<char*> Input3 = parse3->Parse();
	Command* cmd3 = new Command(Input3);
	EXPECT_EQ(cmd3->evaluate(), true);
}

TEST(SingleCommand, Make_and_Remove) {
	string input = "mkdir temp";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
	string input2 = "rm temp";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->Parse();
	Command* cmd2 = new Command(Input2);
	EXPECT_EQ(cmd2->evaluate(), true);
}

TEST(SingleCommand, cat) {
	string input = "cat src/Add.cpp";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
}

TEST(SingleCommand, ps) {
	string input = "ps";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
}

TEST(MultCommand, And) {
	string input = "echo A && echo B";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
	string input2 = "ls && ps";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->Parse();
	Command* cmd2 = new Command(Input2);
	EXPECT_EQ(cmd2->evaluate(), true);
	string input3 = "cat fakeFile && echo C";
	Parser* parse3 = new Parser(input3);
	vector<char*> Input3 = parse3->Parse();
	Command* cmd3 = new Command(Input3);
	EXPECT_EQ(cmd3->evaluate(), true);
}

TEST(MultCommand, Or) {
	string input = "echo A || echo wrong output";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
	string input2 = "ls || echo hello";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->Parse();
	Command* cmd2 = new Command(Input2);
	EXPECT_EQ(cmd2->evaluate(), true);
	string input3 = "cat fakeFile || echo B";
	Parser* parse3 = new Parser(input3);
	vector<char*> Input3 = parse3->Parse();
	Command* cmd3 = new Command(Input3);
	EXPECT_EQ(cmd3->evaluate(), true);
}

TEST(MultCommand, Semi) {
	string input = "echo A; echo B";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
	string input2 = "ls; ps";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->Parse();
	Command* cmd2 = new Command(Input2);
	EXPECT_EQ(cmd2->evaluate(), true);
	string input3 = "cat fakeFile; echo C; ls;";
	Parser* parse3 = new Parser(input3);
	vector<char*> Input3 = parse3->Parse();
	Command* cmd3 = new Command(Input3);
	EXPECT_EQ(cmd3->evaluate(), true);
}

TEST(MultCommand, Comment) {
	string input = "echo A # echo X";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
	string input2 = "ls; ps && echo hello # comment";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->Parse();
	Command* cmd2 = new Command(Input2);
	EXPECT_EQ(cmd2->evaluate(), true);
	string input3 = "ls -a #; ls -lR";
	Parser* parse3 = new Parser(input3);
	vector<char*> Input3 = parse3->Parse();
	Command* cmd3 = new Command(Input3);
	EXPECT_EQ(cmd3->evaluate(), true);
}

TEST(MultCommand, Combo) {
	string input = "echo A && echo B || ls";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
	string input2 = "ls; ps && echo C";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->Parse();
	Command* cmd2 = new Command(Input2);
	EXPECT_EQ(cmd2->evaluate(), true);
	string input3 = "cat file || echo file does not exist && echo D; ls || ls -r";
	Parser* parse3 = new Parser(input3);
	vector<char*> Input3 = parse3->Parse();
	Command* cmd3 = new Command(Input3);
	EXPECT_EQ(cmd3->evaluate(), true);
}

/*
TEST(MultCommand, parentheses) {
	string input = "(echo A && echo B) || (ls -a && echo C)”
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	EXPECT_EQ(cmd->evaluate(), true);
	string input2 = "(echo D; ls) && (mkdir temp && rm -r temp)";
	Parser* parse2 = new Parser(input2);
	vector<char*> Input2 = parse2->Parse();
	Command* cmd2 = new Command(Input2);
	EXPECT_EQ(cmd2->evaluate(), true);
}

TEST(SingleCommand, test) {
	string input = "test /src/Add.cpp”
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
