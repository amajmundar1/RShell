#pragma once
#include "Base.h"
#include <unistd.h>
#include <vector>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;

class Command : public Base
{
	private:
		vector<char*> Input;
		bool empty;
	public:
		Command(vector<char*> input);
		bool evaluate();
};
