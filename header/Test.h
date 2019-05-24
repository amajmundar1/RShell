#ifndef _TEST_H_
#define _TEST_H_

#include "Command.h"

class Test: public Command {
	private: 
		string flag = "-e";
		string file;
	public:
		Test();
		void evaluate();
};

#endif
