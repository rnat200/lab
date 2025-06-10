#include "student.h"

int main() {
	Student* students{ nullptr };
	int32_t size{};

	try {
		std::ifstream fin("students.txt");
		size = CountLines(fin);
		students = new Student[size];
		InputStudentsFromFile(students, size);
	
	}
	catch (const std::exception&e ) {
		std::cerr << "Error : " << e.what() << "\n";
	}
	int32_t choice{};
	do {
		std::cout << "\n Menu: \n";
		std::cout << "1. Sort by name \n";
		std::cout << "2. Find by surname \n";
		std::cout << "3. Sort by group & surname \n";
		std::cout << "4. Average marks in each group \n";
		std::cout << "0. Exit programm \n";
		std::cout << "Input choice: ";
		std::cin >> choice;
		
		try {
			switch (choice)
			{
			case 1:
				SortByName(students, size);
				PrintStudentsFile(students, size);
				break;
			case 2: {
				std::cout << "Enter surname: ";
				char surname[30];
				std::cin >> surname;
				if (FindBySurname(students, size, surname)) {
					std::cout << students[FindBySurname(students, size, surname)].name << std::endl;
					std::cout << students[FindBySurname(students, size, surname)].group << std::endl;
					std::cout << students[FindBySurname(students, size, surname)].grade << std::endl;
				}
				else {
					std::cout << "No student found\n";
				}
				
				break;
			}
			
			case 3:
				SortByGroupAndName(students, size);
				PrintStudents(students, size);
				break;
			case 4:
				PrintAverageByGroup(students, size);
				break;
			case 0:
				std::cout << "Exit.\n";
				break;


			default:
				std::cout << "Wrong choice try again\n";
				break;
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << "\n";
		}


	} while (choice != 0);



	delete[] students;
	return 0;
}
