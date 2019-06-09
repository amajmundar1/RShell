#include "Operator.h"
#include <unistd.h>
#include <stdio.h>

class Pipe : public Operator 
{
	public:
		Pipe(Base* Left, Base* Right) : Operator(Left, Right) {}
		bool evaluate(int Read, int Write);
};
