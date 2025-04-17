#include "header.h"

int main() {
	try {
		int32_t rows{};
		int32_t columns{};
		int32_t minBorder{};
		int32_t maxBorder{};
		InputRowCol(rows, columns);
		InputGenerationBorders(minBorder, maxBorder);
		int32_t** matrix{ nullptr };
		CreateMatrix(matrix, rows, columns);
		FillMatrixWithRandom(matrix, rows, columns, minBorder, maxBorder);
		PrintMatrix(matrix, rows, columns);
		std::cout << "Sum of row with max element is equal " << SumMaxRow(matrix, FindMaxElementRow(matrix, rows, columns), columns)<<std::endl;
		std::cout << "Product of column with min element is equal " << MultiplyMinColumn(matrix, rows, FindMinElementColumn(matrix, rows, columns))<<std::endl;
		DeleteMatrix(matrix, rows);
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