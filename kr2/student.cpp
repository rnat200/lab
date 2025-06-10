#include "student.h"
void CheckInputFile(std::ifstream& fin) {

	if (!fin.good()) {
		throw "file doesn`t exists\n";
	}
	if (!fin) {
		throw"input file error\n";
	}
	if (fin.peek() == EOF) {
		throw "file is empty\n";
	}

}

void CheckOutputFile(std::ofstream& fout) {
	if (!fout) {
		throw"Output file error\n";
	}
}


int32_t CountLines(std::ifstream& fin) {
    int32_t count{};
    std::string line;
    while (std::getline(fin, line)) {
        count++;
    }
    return count;
}

void InputStudentsFromFile(Student* students, int32_t& size) {
    std::ifstream fin("students.txt");
    CheckInputFile(fin);



    char buffer[100];
    int32_t index = 0;

    while (fin.getline(buffer, sizeof(buffer)) && index < size) {
        char* name = strtok(buffer, ";");
        char* groupStr = strtok(nullptr, ";");
        char* gradeStr = strtok(nullptr, ";");

        if (!name || !groupStr || !gradeStr) {
            throw std::runtime_error("Incorrect string in file");
        }
        strncpy(students[index].name, name, sizeof(students[index].name));
        students[index].group = std::atoi(groupStr);
        students[index].grade = std::atof(gradeStr);
        index++;
    }


}

void SortByName(Student* students, int32_t size) {
    for (int32_t i{}; i < size - 1; ++i)
        for (int32_t j{ i + 1 }; j < size; ++j)
            if (strcmp(students[i].name, students[j].name) > 0)
                std::swap(students[i], students[j]);
}

void PrintStudentsFile(const Student* students, int32_t size) {
    std::ofstream fout("students.txt", std::ios::app);
    CheckOutputFile(fout);
    for (int32_t i{}; i < size; ++i) {
        fout << students[i].name << " | : Group " << students[i].group << " |  Average mark: " << students[i].grade << "\n";
    }
    fout.close();
}

void PrintStudents(const Student* students, int32_t size) {
    for (int32_t i{}; i < size; ++i) {
        std::cout << students[i].name << " | : Group " << students[i].group << " |  Average mark: " << students[i].grade << "\n";
    }
}

void SortByGroupAndName(Student* students, int32_t size) {
    for (int32_t i{}; i < size - 1; ++i)
        for (int32_t j{ i + 1 }; j < size; ++j)
            if (students[i].group > students[j].group || (students[i].group == students[j].group && strcmp(students[i].name, students[j].name) > 0))
                std::swap(students[i], students[j]);
}

int32_t FindBySurname(const Student* students, int32_t size, char* surname) {
    for (int32_t i{}; i < size; ++i) {
        if (std::strstr(students[i].name, surname) == students[i].name) {
            return i;
        }
    }
    return -1;
}

void PrintAverageByGroup(const Student* students, int32_t size) {
    const int32_t MAX_GROUPS = 100;
    double total[MAX_GROUPS] = { 0 };
    int32_t count[MAX_GROUPS] = { 0 };

    for (int32_t i = 0; i < size; ++i) {
        int32_t g = students[i].group;
        if (g >= 0 && g < MAX_GROUPS) {
            total[g] += students[i].grade;
            count[g]++;
        }
    }

    for (int32_t g = 0; g < MAX_GROUPS; ++g) {
        if (count[g] > 0) {
            std::cout << "Group " << g << ": avg mark = "
                << total[g] / count[g] << "\n";
        }
    }
}
