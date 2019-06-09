#include "../header/Add.h"

using namespace std;

bool Add::evaluate(int Read, int Write) 
{
	if (Left->evaluate(Read, Write))
		return Right->evaluate(Read, Write);
	else
		return false;
}
