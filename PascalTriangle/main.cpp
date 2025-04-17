#include "header.h"

int main() {
	try {
		int32_t dimension{};
		
		int64_t** matrix{ nullptr };
		InputDimension(dimension);
		int32_t rows{dimension};
		int32_t columns{dimension};
		CreateMatrix(matrix, rows, columns);
		ZeroMatr(matrix, rows,columns);
		PascalTriangle(matrix, dimension);
		PrintMatrix(matrix, rows, columns);	
		DeleteMatrix(matrix,rows);
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