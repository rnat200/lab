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



void GaijinFillMatrix(int32_t**& matrix, int32_t n) {
    int32_t top{};
    int32_t bottom {n - 1};
    int32_t left{ 0 };
    int32_t right{ n - 1 };
    int32_t index{};

        while (top <= bottom && left <= right) {
            for (int32_t i{ left }; i <= right; ++i) {
                std::cin>> matrix[top][i];
            }
            top++;
            for (int32_t i{top}; i <= bottom; ++i) {
                std::cin>> matrix[i][right];
            }
            right--;     
            if (top <= bottom) {
                for (int32_t i { right }; i >= left; --i) {
                    std::cin>>matrix[bottom][i];
                }
                bottom--;
            }    
            if (left <= right) {
                for (int32_t i{ bottom }; i >= top; --i) {
                    std::cin>>matrix[i][left];
                }
                left++;
            }
        }
 }

void InputDimension(int32_t& dimension) {
    std::cout << "Input Dimension\n";
    std::cin >> dimension;
    if (dimension < 1) {
        throw std::invalid_argument("Wrong dimension\n");
    }
}