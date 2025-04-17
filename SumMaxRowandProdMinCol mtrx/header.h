#ifndef HEADER 
#define HEADER
#include <iostream>
#include <random>
#include <iomanip>
void InputRowCol(int32_t&, int32_t&);
void CreateMatrix(int32_t**&, int32_t, int32_t);
void InputGenerationBorders(int32_t&, int32_t&);
void FillMatrixWithRandom(int32_t**&, int32_t, int32_t, int32_t, int32_t);
int32_t FindMaxElementRow(int32_t**, int32_t, int32_t);
int32_t FindMinElementColumn(int32_t**, int32_t, int32_t);
int64_t SumMaxRow(int32_t**, int32_t, int32_t);
int64_t MultiplyMinColumn(int32_t **, int32_t, int32_t);
bool IsRowsandColsareEqual(int32_t, int32_t);



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
}
#endif