#pragma once
#include <unistd.h>
#include "Operator.h"

class Semi: public Operator {
	public:
		Semi(Base* left, Base* right) : Operator(left, right) {};
        	bool evaluate(int Read, int Write);
};

