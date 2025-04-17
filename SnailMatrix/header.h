#ifndef HEADER 
#define HEADER
#include <iostream>
#include <random>
#include <iomanip>
#include <exception>
void InputRowCol(int32_t&, int32_t&);
void CreateMatrix(int32_t**&, int32_t, int32_t);
void GaijinFillMatrix(int32_t**&, int32_t);
void InputDimension(int32_t&);
template <class Type>
void DeleteMatrix(Type**& matrix, int32_t rows) {
	for (int32_t i{}; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}



template <class Type>
void PrintMatrix(Type** matrix, int32_t rows, int32_t columns) {
	for (int32_t i{}; i < rows; ++i) {
		for (int32_t j{}; j < columns; ++j) {
			std::cout << std::setw(4) << matrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
#endif
