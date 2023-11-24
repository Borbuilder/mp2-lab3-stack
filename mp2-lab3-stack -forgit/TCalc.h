#pragma once
#include<iostream>
#include "TStack.h"


class TCalc
{
private:
	std::string infix;
	std::string postfic;
	int priority(char op);
};

