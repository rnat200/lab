#include "header.h"

int main() {
	int32_t size = 0;
	double array[MAX_SIZE]{};

	try {
		InputSize(size);
	}
	catch (const std::invalid_argument& e) {
		std::cout << "������ ����� �������: " << e.what() << std::endl;
		return 1;
	}

	try {
		const int method = SelectFillMethod();
		if (method == 1) {
			InputArrayByKeyboard(array, size);
		}
		else {
			double a, b;
			InputGenerationBorders(a, b);
			RandFillArray(array, size, a, b);
		}
		PrintArray(array, size);
	}
	catch (const std::exception& e) {
		std::cout << "������ ��� ����� �������: " << e.what() << std::endl;
		return 1;
	}

	try {
		switch (SelectTask()) {
		case 1: {
			double number;
			InputNumber(number);
			std::cout << "��������� ������ �����: " << CountElementsLessthanNum(array, size, number) << "\n";
			int last_neg = FindLastNegativeIndex(array, size);
			std::cout << "����� ����� ���������� ��������������: " << SumOfNumbersAfterLastNegative(array, size, last_neg) << "\n";
			TransformArray(array, size, number);
			std::cout << "��������������� ������:\n";
			PrintArray(array, size);
			break;
		}
		case 2: {
			std::cout << "������������ �������������: " << ProductOfPositive(array, size) << "\n";
			std::cout << "����� �� ������� ��������: " << SumBeforeFirstMinElement(array, size) << "\n";
			SortEvenAndOddIndex(array, size);
			std::cout << "��������������� ������:\n";
			PrintArray(array, size);
			break;
		}
		default:
			throw std::invalid_argument("Wrong Task number");
		}
	}
	catch (const std::exception& e) {
		std::cout << "������ ���������� ������: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
