#include <unistd.h>
#include "Operator.h"

class Add: public Operator {
	private:
		Base* Left;
		Base* Right;
	public:
		Add();
		Add(Base* left, Base* right);
		string evaluate();
};

