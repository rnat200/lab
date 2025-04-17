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

int32_t FindMaxElementRow(int32_t** matrix, int32_t rows, int32_t columns) {
	int32_t maxElementRow{0};
	int32_t maxElement{ matrix[0][0] };
	for (int32_t i{}; i < rows; ++i) {
		for (int32_t j{}; j < columns; ++j) {
			if (maxElement < matrix[i][j]) {
				maxElementRow = i;
				maxElement = matrix[i][j];
			}
		}
	}
	return maxElementRow;
}

int32_t FindMinElementColumn(int32_t** matrix, int32_t rows, int32_t columns) {
	int32_t minElementColumn{ 0 };
	int32_t minElement{ matrix[0][0] };
	for (int32_t i{}; i < rows; ++i) {
		for (int32_t j{}; j < columns; ++j) {
			if (minElement >= matrix[i][j]) {
				minElementColumn = j;
				minElement = matrix[i][j];
			}
		}
	}
	return minElementColumn;
}

int64_t SumMaxRow(int32_t** matrix, int32_t maxElementRow,  int32_t columns) {

	int64_t sum{};
	for (int32_t i{}; i < columns; ++i) {
		sum += matrix[maxElementRow][i];
	}
	return sum;
}

int64_t MultiplyMinColumn(int32_t** matrix, int32_t rows, int32_t minElementColumn) {

	int64_t product{1};
	for (int32_t i{}; i < rows; ++i) {
		product *= matrix[i][minElementColumn];
	}
	return product;
}

bool IsRowsandColsareEqual(int32_t col, int32_t row) {
	return (col == row);
}