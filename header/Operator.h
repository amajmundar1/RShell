#include <iostream>
#include "Base.h"

class Operator: public Base {
protected:
        Base* Left;
        Base* Right;
public:
	Operator(): Left(NULL), Right(NULL) {};
        Operator(Base* left, Base* right): Left(left), Right(right) {};
        virtual bool evaluate() = 0;
};
