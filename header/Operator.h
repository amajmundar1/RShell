#include <iostream>
#include "Base.h"

class Operator: public Base {
private:
        Base* Left;
        Base* Right;
public:
	Operator(): Left(NULL), Right(NULL) {};
        Operator(Base* left, Base* right): Left(left), Right(right) {};
        virtual string evaluate() = 0;
};
