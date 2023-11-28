#include <iostream>
#include<string>
#include "TCalc.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	/*
	//Калькулятор
	std::cout << "Введите выражение" << std::endl;
	std::string expression;
	std::cin >> expression;
	TCalc m(expression);
	std::cout <<"Результат:"<<std::endl<<expression << " = " << m.CalculateNoPostfix()<<std::endl;*/
	TStack<int> st(5);
	for (int i = 1; i <= 5; i++)
	{
		st.Push(i);
	}
	TStack<int> st1(st);
	st.output();
	st1.output();
	for (int i = 1; i <= 5; i++)
	{
		std::cout<<i<<": "<<st.Pop()<<" "<<st1.Pop()<<std::endl;
	}
	

};