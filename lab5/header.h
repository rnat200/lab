#ifndef HEADER 
#define HEADER
#include <iostream>
const int32_t MAX_SIZE{ 100 };
void InputSize(int32_t&);
int32_t SelectTask();
int32_t SelectFillMethod();
void RandFillArray(int64_t*, int32_t&, int64_t, int64_t);
void  RandFillArray(double*, int32_t&, double, double);
int32_t FindLastNegativeIndex(double*, int32_t);
int32_t CountElementsLessthanNum(double*, int32_t, double);
int64_t SumOfNumbersAfterLastNegative(double*, int32_t, int32_t);
void TransformArray(double*&, int32_t, double);
void InputNumber(double&);
double ProductOfPositive(double*& array, int32_t);
double SumBeforeFirstMinElement(double*&, int32_t);
int32_t FindIndexofFirstMinElement(double*&, int32_t);
void SortEvenAndOddIndex(double*&, int32_t);
template <class Type>
void CreateArray(Type*& array, int32_t size) {
	array = new Type[size];
}

template <class Type>
void DeleteArray(Type*& array) {
	delete [] array;
}

template <class Type>
void PrintDynamicArray(Type*& array, int32_t size) {
	for (int32_t i{}; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << '\n';
}


template <class Type>
void InputArraybyKeyboard(Type* array, int32_t size) {
	std::cout << "Input array elements\n";
	for (size_t i{ 0 }; i < size; ++i) {
		std::cin >> array[i];
	}
}



template <class Type>
void InputGenerationBorders(Type& a, Type& b) {
	std::cout << "Input Generation borders\n";
		std::cin >> a >> b;
	if (a > b) {
		std::swap(a, b);
	}
}
#endif
