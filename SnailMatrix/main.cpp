#include "header.h"

int main() {
	try {
		int32_t dimension{};
		InputDimension(dimension);
		int32_t rows{ dimension };
		int32_t columns{ dimension };;
		int32_t** matrix{ nullptr };
		CreateMatrix(matrix, rows, columns);
		GaijinFillMatrix(matrix, dimension);
		PrintMatrix(matrix, rows, columns);

		
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