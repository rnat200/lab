#include "functions.h"
void Task11() {
    std::cout << "Task 11: \n";
        int16_t size;
        std::cout << "Enter matrix size (odd positive integer): ";
        if (!(std::cin >> size)) {
            throw std::invalid_argument("Invalid input: not a number");
        }
    int32_t** matrix = CreateSpiralMatrix(size);
    PrintMatrix(matrix, size);
    int64_t sum = CalculateLowerRightTriangleSum(matrix, size);
    std::cout << "Sum of lower right triangle: " << sum << "\n";
    DeleteMatrix(matrix, size);
}


int32_t** CreateSpiralMatrix(int16_t size) {
    if (size <= 0) {
        throw std::invalid_argument("Matrix size must be positive");
    }
    if (size % 2 == 0) {
        throw std::invalid_argument("Matrix size must be odd");
    }

    int32_t** matrix = nullptr;

    matrix = new int32_t * [size];
    for (int16_t i{}; i < size; ++i) {
        matrix[i] = new int32_t[size]{};
    }


    const int16_t center{ size / 2 };
    int32_t x {center};
    int32_t y {center};
    int32_t currentNumber{ 1 };
    int16_t step{ 1 };
    uint8_t directionIndex{};

    const int16_t directionx[4] = { 0, 1, 0, -1 };
    const int16_t directiony[4] = { -1, 0, 1, 0 };

    matrix[y][x] = currentNumber++;
    const int32_t totalNumbers = size * size;

    while (currentNumber <= totalNumbers) {
        for (int16_t k = 0; k < 2; ++k) {
            for (int16_t i = 0; i < step; ++i) {
                if (currentNumber > totalNumbers) break;

                x += directionx[directionIndex];
                y += directiony[directionIndex];

                if (x < 0 || x >= size || y < 0 || y >= size) {
                    continue;
                }

                matrix[y][x] = currentNumber++;
            }
            if (currentNumber > totalNumbers) break;
            directionIndex = (directionIndex + 1) % 4;
        }
        ++step;
    }

    return matrix;
}

int64_t CalculateLowerRightTriangleSum(int32_t** matrix, int16_t size) {
    int64_t sum{};
    for (int16_t i{}; i < size; ++i) {
        for (int16_t j{}; j < size; ++j) {
            if (i + j >= size - 1) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

void PrintMatrix(int32_t** matrix, int16_t size) {
    for (int16_t i{}; i < size; ++i) {
        for (int16_t j{}; j < size; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void DeleteMatrix(int32_t** matrix, int16_t size) {
    for (int16_t i{}; i < size; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}