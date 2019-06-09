#include "../header/Semi.h"

using namespace std;

bool Semi::evaluate(int Read, int Write) 
{
	if(Left != nullptr)
		Left->evaluate(Read, Write);
	if(Right != nullptr)
		return Right->evaluate(Read, Write);
	return false;
}

