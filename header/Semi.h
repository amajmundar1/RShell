#include <unistd.h>
#include "Operator.h"

class Semi: public Operator {
	private:
		Base* Left;
		Base* Right;
	public:
		Semi();
		Semi(Base* left, Base* right);
        	string evaluate();
};

