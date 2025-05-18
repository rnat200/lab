#ifndef HEADER 
#define HEADER

#include <iostream>
#include <cstdlib>
#include <ctime>

const int32_t MAX_SIZE{ 100 };

void InputSize(int32_t&);
int32_t SelectTask();
int32_t SelectFillMethod();
void RandFillArray(int64_t* array, int32_t size, int64_t a, int64_t b);
void RandFillArray(double* array, int32_t size, double a, double b);
int32_t FindLastNegativeIndex(double* array, int32_t size);
int32_t CountElementsLessthanNum(double* array, int32_t size, double num);
int64_t SumOfNumbersAfterLastNegative(double* array, int32_t size, int32_t index);
void TransformArray(double* array, int32_t size, double number);
void InputNumber(double&);
double ProductOfPositive(double* array, int32_t size);
double SumBeforeFirstMinElement(double* array, int32_t size);
int32_t FindIndexofFirstMinElement(double* array, int32_t size);
void SortEvenAndOddIndex(double* array, int32_t size);

template <class Type>
void PrintArray(Type* array, int32_t size) {
	for (int32_t i = 0; i < size; ++i)
		std::cout << array[i] << " ";
	std::cout << '\n';
}

template <class Type>
void InputArrayByKeyboard(Type* array, int32_t size) {
	std::cout << "Input array elements:\n";
	for (int32_t i = 0; i < size; ++i)
		std::cin >> array[i];
}

template <class Type>
void InputGenerationBorders(Type& a, Type& b) {
	std::cout << "Input generation borders:\n";
	std::cin >> a >> b;
	if (a > b)
		std::swap(a, b);
}

#endif
