#pragma once
#include<iostream>

template <class T>
class TStack
{
private:
	T* pMem;
	int MaxSize;
	int CurrentIndex;

public:
	
	TStack(int ms);   // ����������� �� ���������
	TStack(const TStack& StackObject);  // ����������� �����������

	bool operator ==(const TStack& StackObject);  // �������� ���������
	bool operator !=(const TStack& StackObject);  // �������� ��������� 2
	TStack& operator = (const TStack& StackObject);  // �������� ������������

	bool empty(); // ����� �������� ����� �� �������
	bool full(); // ����� �������� ����� �� �������
	int ElementsNumber(); // ���������� ��������� � �����
	void output(); // ����� ������ ����� �� ����� 
	void Push(const T element); // ����� ���������� �������� � ����
	void ClerStack();  // ����� ������� �����
	T Pop(); // ����� ��������� ������� ����� (c � ������������)
	T Top(); // ����� ��������� �������� ������� �����
};


//���������� ������� ������ TStack

template <class T> //����������� �� ���������
TStack<T>::TStack(int ms) 
{
	if (ms < 1)
	{
		throw "������������  MaxSize � ������� ������ TStack";
	}
	MaxSize = ms;
	pMem = new T[MaxSize];
	CurrentIndex = -1;
}

template <class T> // ����������� �����������
TStack<T>::TStack(const TStack& StackObject)
{
	MaxSize = StackObject.MaxSize;
	delete[] pMem;
	pMem = new T[MaxSize];
	CurrentIndex = StackObject.CurrentIndex;
	std::copy(StackObject.pMem, StackObject.pMem + (CurrentIndex+1), pMem);
}

template <class T> //�������� ���������
bool TStack<T>:: operator ==(const TStack& StackObject)
{
	if ((CurrentIndex) != (StackObject.CurrentIndex))
	{
		return false;
	}
	for (int i = 0; i < CurrentIndex; i++)
	{
		if (pMem[i] != StackObject.pMem[i])
		{
			return false;
		}
	}
	return true;
}

template <class T> //�������� ��������� 2
bool TStack<T>:: operator !=(const TStack& StackObject)
{
	return !(*this == StackObject);
}

template <class T> //�������� ������������
TStack<T>& TStack<T>::operator = (const TStack& StackObject)
{
	if (*this != StackObject)
	{
		delete[] pMem;
		MaxSize = StackObject.MaxSize;
		CurrentIndex = StackObject.CurrentIndex;
		pMem = new T[MaxSize];
		std::copy(StackObject.pMem, StackObject.pMem + (CurrentIndex+1), pMem);
	}
	return *this;
}

template <class T> //�������� �� �������
bool TStack<T>::empty()
{
	if (CurrentIndex == -1)
	{
		return true;
	}
	return false;
}

template <class T> //�������� �� �������
bool TStack<T>::full()
{
	if (CurrentIndex == MaxSize - 1)
	{
		return true;
	}
	return false;
}

template <class T> //���������� ���������
int TStack<T>::ElementsNumber()
{
	return CurrentIndex + 1;
}

template<class T>//�����
void TStack<T>::output()
{
	if (CurrentIndex == -1)
	{
		throw "Stack is empty";
	}
	std::cout << "( ";
	for (int i = 0; i <= CurrentIndex; i++)
	{
		std::cout << pMem[CurrentIndex - i] << " ";
	}
	std::cout << ")" << std::endl;
}

template <class T> //���������� ��������
void TStack<T>::Push(const T element)
{
	if (CurrentIndex + 1 >= MaxSize)
	{
		throw "Stack is overfloated";
	}
	pMem[CurrentIndex + 1] = element;
	CurrentIndex++;
}

template <class T> //��������� �������
T TStack<T>::Pop()
{
	if (CurrentIndex == -1)
	{
		throw "Stack is empty";
	}
	CurrentIndex--;
	return pMem[CurrentIndex + 1];
}

template <class T> //�������� �������
T TStack<T>::Top()
{
	if (CurrentIndex == -1)
	{
		throw "Stack is empty";
	}
	return pMem[CurrentIndex];
}

template <class T> //������� ����� ????? ����� �� ������ Pop ��� ������� ��������
void TStack<T>::ClerStack()
{
	CurrentIndex = -1;
}