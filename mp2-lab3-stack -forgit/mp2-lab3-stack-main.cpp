#include <iostream>
#include<string>
#include "TCalc.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	//�����������
	std::cout << "������� ���������" << std::endl;
	std::string expression;
	std::cin >> expression;
	TCalc m(expression);
	std::cout <<"���������:"<<std::endl<<expression << "=" << m.CalculateNoPostfix()<<std::endl;

};