#include <iostream>
#include "Base.h"

class Operator: public Base {
private:
        Base* Left;
        Base* Right;
public:
        Operator(Left, Right): Left(Left), Right(Right) {};
        virtual string evaluate() = 0;
}
