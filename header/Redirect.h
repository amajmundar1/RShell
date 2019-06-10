#pragma once

#include "Base.h"
#include <fcntl.h>
#include <cstring>
#include <sys/types.h>

class Redirect : public Base
{
	protected:
		Base* Command;
		char* File;
	public:
		Redirect(Base* command, char* file) : Command(command), File(file) {}
		virtual bool evaluate(int Read, int Write) = 0;
};


class RedirectInput : public Redirect
{
	public:
		RedirectInput(Base* command, char* file) : Redirect(command, file) {}
		bool evaluate(int Read, int Write);
};

class RedirectOutput : public Redirect
{
	public:
		RedirectOutput(Base* command, char* file) : Redirect(command, file) {}
		bool evaluate(int Read, int Write);
};

class AppendOutput : public Redirect
{
	public:
		AppendOutput(Base* command, char* file) : Redirect(command, file) {}
		bool evaluate(int Read, int Write);
};
