#pragma once
#include <unistd.h>
#include "Operator.h"

class Or: public Operator {
	public:
		Or();
		Or(Base* left, Base* right) : Operator(left, right) {};
		bool evaluate();
};
