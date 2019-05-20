#include "../header/Add.h"

using namespace std;

bool Add::evaluate() 
{
	if (Left->evaluate())
		return Right->evaluate();
	else
		return false;
}
