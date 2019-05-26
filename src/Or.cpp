#include "../header/Or.h"
//#include "Parser.h"

using namespace std;

bool Or::evaluate() {
	if(Left->evaluate())
		return true;
	else if (Right->evaluate())
		return true;
	else
		return false;
}
