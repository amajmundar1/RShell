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

TEST(SingleCommand, CommandTestSet)
{
	string input = "echo hello";
	Parser* parse = new Parser(input);
	vector<char*> Input = parse->Parse();
	Command* cmd = new Command(Input);
	cmd->evaluate();
	EXPECT_EQ(true, cmd->evaluate());
}


int main(int argc, char **argv) {
     ::testing::InitGoogleTest(&argc, argv);
     return RUN_ALL_TESTS();
}
