#include <iostream>
#include<string>
#include "TCalc.h"

int sravn(const int *arrr,const int *arrr2) {
	if (arrr == arrr2) {
		return 1;
	}
	return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	TCalc m("(2+2)*(3+1)");
	std::cout << m.Calculate();

};