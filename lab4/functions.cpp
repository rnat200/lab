#include "header.h"

void InputNumber(double& number) {
	std::cout << "Input real number\n";
	std::cin >> number;
}

void InputSize(int32_t& size) {
	std::cout << "Input array size (<= " << MAX_SIZE << ")\n";
	std::cin >> size;
	if (size <= 0 || size > MAX_SIZE) {
		throw std::invalid_argument("Wrong size");
	}
}

void TransformArray(double* array, int32_t size, double number) {
	int32_t pos = 0;
	for (int32_t i = 0; i < size; ++i) {
		if (array[i] < number) {
			double temp = array[i];
			for (int32_t j = i; j > pos; --j) {
				array[j] = array[j - 1];
			}
			array[pos++] = temp;
		}
	}
}

double ProductOfPositive(double* array, int32_t size) {
	bool has_positive = false;
	double product = 1;
	for (int32_t i = 0; i < size; ++i) {
		if (array[i] > 0) {
			has_positive = true;
			product *= array[i];
		}
	}
	if (!has_positive) {
		throw std::domain_error("No positive elements in array");
	}
	return product;
}

int32_t FindIndexofFirstMinElement(double* array, int32_t size) {
	int32_t index = 0;
	for (int32_t i = 1; i < size; ++i) {
		if (array[i] < array[index]) {
			index = i;
		}
	}
	return index;
}

double SumBeforeFirstMinElement(double* array, int32_t size) {
	int32_t index = FindIndexofFirstMinElement(array, size);
	double sum = 0;
	for (int32_t i = 0; i < index; ++i) {
		sum += array[i];
	}
	return sum;
}

int32_t SelectTask() {
	int32_t selector;
	std::cout << "Select Task\n1. Task 1\n2. Task 2\n";
	std::cin >> selector;
	if (selector != 1 && selector != 2) {
		throw std::invalid_argument("Wrong Task number");
	}
	return selector;
}

int32_t SelectFillMethod() {
	int32_t selector;
	std::cout << "Select array type\n1. Keyboard input\n2. Random fill\n";
	std::cin >> selector;
	if (selector != 1 && selector != 2) {
		throw std::invalid_argument("Wrong FillMethod");
	}
	return selector;
}

int32_t FindLastNegativeIndex(double* array, int32_t size) {
	for (int32_t i = size - 1; i >= 0; --i) {
		if (array[i] < 0) {
			return i;
		}
	}
	throw std::domain_error("There are no negative numbers in array");
}

int64_t SumOfNumbersAfterLastNegative(double* array, int32_t size, int32_t index) {
	int64_t sum = 0;
	for (int32_t i = index + 1; i < size; ++i) {
		sum += static_cast<int32_t>(array[i]);
	}
	return sum;
}

int32_t CountElementsLessthanNum(double* array, int32_t size, double num) {
	int32_t counter = 0;
	for (int32_t i = 0; i < size; ++i) {
		if (array[i] < num) {
			++counter;
		}
	}
	return counter;
}

void RandFillArray(int64_t* array, int32_t size, int64_t a, int64_t b) {
	srand(static_cast<unsigned int>(time(NULL)));
	for (int32_t i = 0; i < size; ++i) {
		array[i] = a + (rand() % (b + 1 - a));
	}
}

void RandFillArray(double* array, int32_t size, double a, double b) {
	srand(static_cast<unsigned int>(time(NULL)));
	for (int32_t i = 0; i < size; ++i) {
		array[i] = a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
	}
}

void SortEvenAndOddIndex(double* array, int32_t size) {
	bool swapped = true;
	while (swapped) {
		swapped = false;
		for (int32_t j = 0; j < size - 2; j += 2) {
			if (array[j] > array[j + 2]) {
				std::swap(array[j], array[j + 2]);
				swapped = true;
			}
		}
	}
	swapped = true;
	while (swapped) {
		swapped = false;
		for (int32_t j = 1; j < size - 2; j += 2) {
			if (array[j] > array[j + 2]) {
				std::swap(array[j], array[j + 2]);
				swapped = true;
			}
		}
	}
}
