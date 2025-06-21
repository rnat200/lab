#include "header.h"

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    int32_t size = 0;
    double* array = nullptr;

    try {
        InputSize(size);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Ошибка ввода размера: " << e.what() << std::endl;
    }

    try {
        CreateArray(array, size);
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Ошибка выделения памяти: " << e.what() << std::endl;
    }

    try {
        const int method = SelectFillMethod();
        
        if (method == 1) {
            InputArraybyKeyboard(array, size);
        }
        else {
            double a, b;
            InputGenerationBorders(a, b);
            RandFillArray(array, size, a, b);
        }
        PrintDynamicArray(array, size);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Ошибка выбора метода: " << e.what() << std::endl;
        DeleteArray(array);
    }
    catch (const std::domain_error& e) {
        std::cout << "Ошибка границ генерации: " << e.what() << std::endl;
        DeleteArray(array);
    }
    catch (const std::system_error& e) {
        std::cout << "Системная ошибка: " << e.what() << std::endl;
        DeleteArray(array);
    }

    try {
        switch (SelectTask()) {
            case 1: {
                try {
                    double number;
                    InputNumber(number); 
                    std::cout << "Элементов меньше числа: " << CountElementsLessthanNum(array, size, number) << "\n";
                    const int last_neg = FindLastNegativeIndex(array, size);
                    std::cout << "Сумма после последнего отрицательного: " << SumOfNumbersAfterLastNegative(array, size, last_neg) << "\n";
                    TransformArray(array, size, number);
                    std::cout << "Преобразованный массив:\n";
                    PrintDynamicArray(array, size);
                }
                catch (const std::domain_error& e) {
                    std::cout << "Ошибка в задаче 1: " << e.what() << std::endl;
                }
                break;
            }
            
            case 2: {
                try {
                    std::cout << "Произведение положительных: "<< ProductOfPositive(array, size) << "\n";
                    std::cout << "Сумма до первого минимума: " << SumBeforeFirstMinElement(array, size) << "\n";
                    SortEvenAndOddIndex(array, size);
                    std::cout << "Отсортированный массив:\n";
                    PrintDynamicArray(array, size);
                }
                catch (const std::domain_error& e) {
                    std::cout << "Ошибка в задаче 2: " << e.what() << std::endl;
                }
                break;
            }
        }
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Ошибка выбора задачи: " << e.what() << std::endl;
    }

    DeleteArray(array);
    return 0;
}
