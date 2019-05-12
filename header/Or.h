#include <unistd.h>
#include "Operator.h"

class Or: public Operator {
	private:
		Base* Left;
		Base* Right;
	public:
		Or();
		Or(Base* left, Base* right);
		string evaluate();
};
