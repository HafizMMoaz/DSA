/*
	Pointers in C++ - Implementation with Examples

	Topics covered:
	1) Basic pointer declaration and dereference
	2) Pointer arithmetic with arrays
	3) Passing pointer to functions
	4) Pointer to pointer
	5) Dynamic memory allocation (new/delete)
*/

#include <iostream>
using namespace std;

void updateValue(int* ptr, int newValue) {
	if (ptr != nullptr) {
		*ptr = newValue;
	}
}

int sumArray(const int* arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(arr + i);
	}
	return sum;
}

int main() {
	cout << "1) Basic Pointer" << endl;
	int number = 10;
	int* pNumber = &number;

	cout << "number value      : " << number << endl;
	cout << "number address    : " << &number << endl;
	cout << "pNumber (address) : " << pNumber << endl;
	cout << "*pNumber (value)  : " << *pNumber << endl;

	*pNumber = 25;
	cout << "After *pNumber = 25, number = " << number << endl;

	cout << "\n2) Pointer Arithmetic with Array" << endl;
	int arr[5] = {2, 4, 6, 8, 10};
	int* pArr = arr;

	for (int i = 0; i < 5; i++) {
		cout << "arr[" << i << "] = " << *(pArr + i)
			 << " (address: " << (pArr + i) << ")" << endl;
	}

	cout << "\n3) Pass Pointer to Function" << endl;
	int value = 100;
	cout << "Before updateValue: " << value << endl;
	updateValue(&value, 500);
	cout << "After updateValue : " << value << endl;

	int total = sumArray(arr, 5);
	cout << "sumArray(arr, 5)  : " << total << endl;

	cout << "\n4) Pointer to Pointer" << endl;
	int x = 7;
	int* pX = &x;
	int** ppX = &pX;

	cout << "x                 : " << x << endl;
	cout << "pX                : " << pX << endl;
	cout << "*pX               : " << *pX << endl;
	cout << "ppX               : " << ppX << endl;
	cout << "*ppX              : " << *ppX << endl;
	cout << "**ppX             : " << **ppX << endl;

	cout << "\n5) Dynamic Memory (new/delete)" << endl;
	int* dynamicNumber = new int(42);
	cout << "dynamicNumber value: " << *dynamicNumber << endl;

	*dynamicNumber = 99;
	cout << "updated dynamic value: " << *dynamicNumber << endl;

	delete dynamicNumber;
	dynamicNumber = nullptr;

	int size = 4;
	int* dynamicArray = new int[size];
	for (int i = 0; i < size; i++) {
		dynamicArray[i] = (i + 1) * 10;
	}

	cout << "dynamic array values: ";
	for (int i = 0; i < size; i++) {
		cout << dynamicArray[i] << " ";
	}
	cout << endl;

	delete[] dynamicArray;
	dynamicArray = nullptr;

	cout << "\nAll pointer examples completed." << endl;

	return 0;
}
