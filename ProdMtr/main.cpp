#include "header.h"

int main() {
	try {
		int32_t rows1{};
		int32_t columns1{};
		

		int32_t minBorder{};
		int32_t maxBorder{};
		InputRowCol(rows1, columns1);
		InputGenerationBorders(minBorder, maxBorder);
		int32_t** matrix1{ nullptr };

		CreateMatrix(matrix1, rows1, columns1);
		FillMatrixWithRandom(matrix1, rows1, columns1, minBorder, maxBorder);
		PrintMatrix(matrix1, rows1, columns1);
		int32_t** matrix2{ nullptr };
		int32_t rows2{};
		int32_t columns2{};
		InputRowCol(rows2, columns2);
		CreateMatrix(matrix2, rows2, columns2);
		FillMatrixWithRandom(matrix2, rows2, columns2, minBorder, maxBorder);
		PrintMatrix(matrix2, rows2, columns2);
		int32_t** matrix3{ nullptr };
		CreateMatrix(matrix3, rows1, columns2);
		ProductMatrix(matrix1, matrix2, matrix3, rows1, columns1, rows2, columns2);
		std::cout << "Result of production matrix are equal martrix: \n";
		PrintMatrix(matrix3, rows1, columns2);
		DeleteMatrix(matrix1, rows1);
		DeleteMatrix(matrix2, rows2);
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what();
	}
	catch (std::bad_array_new_length& e) {
		std::cout << e.what();
	}
	catch (std::bad_alloc& e) {
		std::cout << e.what();
	}

	return 0;
}