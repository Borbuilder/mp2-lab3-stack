#include "TCalc.h"

int TCalc::priority(char op)
{
	switch (op)
	{
	case '+' :
		return 1;
	case '-' :
		return 1;
	case '/':
		return 2;
	case '*':
		return 2;
	case '^':
		return 3;
	case '(':
		return 0;
	default:
		break;
	}
}
