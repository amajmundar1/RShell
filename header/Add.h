#pragma once
#include <unistd.h>
#include "Operator.h"

class Add: public Operator {
	public:
		Add(Base* left, Base* right) : Operator(left, right) {};
		bool evaluate();
};

