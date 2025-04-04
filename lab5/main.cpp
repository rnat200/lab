#include <iostream>
#include "header.h"

int main() {
	try {
		int32_t size{  };
		InputSize(size);
		double* array{ nullptr };
		CreateArray(array, size);

		if (SelectFillMethod() == 1) {
			InputArraybyKeyboard(array, size);
			PrintDynamicArray(array, size);
		}
		else {
			double a{}, b{};
			InputGenerationBorders(a, b);
			RandFillArray(array, size, a, b);
			PrintDynamicArray(array, size);
		}

		switch (SelectTask())
		{
		case(1): {
			double number{ };
			InputNumber(number);
			std::cout << "Count of array elements less than number is " << CountElementsLessthanNum(array, size, number) << std::endl;
			std::cout << "Sum of array elements between negative numbers is " << SumOfNumbersAfterLastNegative(array, size, FindLastNegativeIndex(array,size)) << std::endl;
			TransformArray(array, size, number);
			std::cout << "Sorted array is :\n";
			PrintDynamicArray(array, size);
			DeleteArray(array);
			break;
		}
		case(2): {
			std::cout << "Product of positive array elements is " << ProductOfPositive(array, size) << std::endl;
			std::cout << "Sum of elements before first min element is " << SumBeforeFirstMinElement(array, size) << std::endl;
			SortEvenAndOddIndex(array, size);
			std::cout << "Sorted array is :\n";
			PrintDynamicArray(array, size);
			DeleteArray(array);
			break;
		}
		}
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	catch (std::domain_error& e) {
		std::cout << e.what();
	}
	catch (std::bad_alloc& e) {
		std::cout << e.what();
	}
	catch (std::system_error& e) {
		std::cout << e.what();
	}
	return 0;
}