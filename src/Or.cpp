#include "../header/Or.h"
//#include "Parser.h"

using namespace std;

bool Or::evaluate(int Read, int Write) {
	if(Left->evaluate(Read, Write))
		return true;
	else if (Right->evaluate(Read, Write))
		return true;
	else
		return false;
}
