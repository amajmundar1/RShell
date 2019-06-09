#pragma once
#include <iostream>
#include <string>

using namespace std;

class Base {
public:
	virtual bool evaluate(int Read, int Write) = 0;
};
