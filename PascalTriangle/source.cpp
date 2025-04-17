#include "header.h"


void CreateMatrix(int64_t**& matrix, int32_t rows, int32_t columns) {
	matrix = new int64_t * [rows];
	for (int32_t i{}; i < rows; ++i) {
		matrix[i] = new int64_t[columns];
	}
}

void InputDimension(int32_t& dimension) {
	std::cout << "Input Dimension\n";
	std::cin >> dimension;
	if (dimension < 1) {
		throw std::invalid_argument("Wrong dimension\n");
	}
}

void FillMatrixWithRandom(int64_t**& matrix, int32_t rows, int32_t columns, int32_t a, int32_t b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(a, b);

	for (int32_t i{ 0 }; i < rows; ++i) {
		for (int32_t j{}; j < columns; ++j) {
			matrix[i][j] = dis(gen);
		}
	}
}

int64_t C(int32_t n, int32_t k) {
	return (Factorial(n) / (Factorial(n - k) * Factorial(k)));
}

int64_t Factorial(int32_t n) {
	int64_t fact{1};
	while (n) {
		fact *= n;
		n -= 1;
	}
	return fact;
}

void ZeroMatr(int64_t**& matrix, int32_t rows, int32_t columns) {
	for (int32_t i{}; i < rows; ++i) {
		for (int32_t j{}; j < columns; ++j) {
			matrix[i][j] = 0;
		}
	}
}

void PascalTriangle(int64_t**& matrix, int32_t dimension) {
	for (int32_t i{}; i < dimension; ++i) {
		for (int32_t j{}; j <= i; ++j) {
			matrix[i][0] = 1;
			if (i == j) {
				matrix[i][i] = 1;
			}
			else {

				matrix[i][j] = C(i, j);
			}
		}
	}
}