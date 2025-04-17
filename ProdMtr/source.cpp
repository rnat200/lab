#include "header.h"
void InputRowCol(int32_t& rows, int32_t& columns) {
	std::cout << "Input rows and columns\n";
	std::cin >> rows >> columns;

	if (rows <= 0 || columns <= 0) {
		throw std::invalid_argument("Wrong rows or columns argument");
	}
}

void CreateMatrix(int32_t**& matrix, int32_t rows, int32_t columns) {
	matrix = new int32_t * [rows];
	for (int32_t i{}; i < rows; ++i) {
		matrix[i] = new int32_t[columns];
	}
}

void InputGenerationBorders(int32_t& a, int32_t& b) {
	std::cout << "Input low border and high border\n";
	std::cin >> a >> b;
	if (a > b) {
		std::swap(a, b);
	}
}

void FillMatrixWithRandom(int32_t**& matrix, int32_t rows, int32_t columns, int32_t a, int32_t b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(a, b);

	for (int32_t i{ 0 }; i < rows; ++i) {
		for (int32_t j{}; j < columns; ++j) {
			matrix[i][j] = dis(gen);
		}
	}
}

bool IsRowsandColsareEqual(int32_t col, int32_t row) {
	return (col == row);
}

void ProductMatrix(int32_t** matrix1, int32_t** matrix2, int32_t**& matrix3, int32_t rows1, int32_t col1, int32_t rows2, int32_t col2) {
	if (!IsRowsandColsareEqual(col1,rows2)) {
		throw std::invalid_argument("Columns 1 aren`t equal rows 2");
	}
	
	for (int32_t i{}; i < rows1; ++i) {
		for (int32_t j{}; j < col2; ++j) {
			int64_t sum{};
			for (int32_t k{}; k < col1; ++k) {
				sum += matrix1[i][k] * matrix2[k][j];
			}
			matrix3[i][j] = sum;
		}
	}
}