#include <iostream>

int sravn(const int *arrr,const int *arrr2) {
	if (arrr == arrr2) {
		return 1;
	}
	return 0;
}

int main()
{
	int size = 3; int size2 = 5;
	int* arr; int* arr2;
	arr = new int[size];
	arr2 = new int[size2];
	std::cout << sravn(arr, arr);

};