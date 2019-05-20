#include "../header/Semi.h"

using namespace std;

bool Semi::evaluate() 
{
	if(Left != nullptr)
		return Left->evaluate();
	if(Right != nullptr)
		return Right->evaluate();
	return false;
}

