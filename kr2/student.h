#ifndef STUDENT
#define	STUDENT
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
struct Student
{
	char name[30];
	int group;
	double grade;

};

void CheckInputFile(std::ifstream&);
void CheckOutputFile(std::ofstream&);
int32_t CountLines(std::ifstream&);
void InputStudentsFromFile( Student*, int32_t&);
void SortByName(Student*, int32_t);
void PrintStudentsFile(const Student*, int32_t);
void PrintStudents(const Student*, int32_t);
void PrintAverageByGroup(const Student*, int32_t);
void SortByGroupAndName(Student*, int32_t);
int32_t FindBySurname(const Student*, int32_t, char*);
#endif
