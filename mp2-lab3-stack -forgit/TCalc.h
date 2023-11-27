#pragma once
#include<iostream>
#include<string>
#include "TStack.h"


class TCalc
{
private:
	std::string infix; // ��������� ������, ���������� �� ����
	std::string postfix; // ����������� ������

	TStack<char> OpStack = TStack<char>(10); // ���� �� �������� "+", "-", ")" � ��
	TStack<double> NumStack = TStack<double>(10); // ���� �� ����� �� ��������� ������

	int priority(char op); // ����� , ������������ ��������� ��������
	void ToPostfix(); // ����� �������� ��������� ������ � �����������

public:
	std::string GetInfix() { return infix; } // �������� ��������� ������
	std::string GetPostfix() { return postfix; } // �������� ��������� ������
	void SetInfix(std::string _infix) { infix = _infix; } // �������� ������ � �������� ������

	TCalc(std::string _infix) :infix(_infix) { ToPostfix(); } // ����������� �� ���������
	double CalculateWithPostfix(); // ����� ���������� c ����������� 
	double CalculateNoPostfix(); // ����� ���������� 

	
};

