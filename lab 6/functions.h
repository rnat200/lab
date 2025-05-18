#ifndef HEADER
#define HEADER
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
const int32_t MAX_STRING_SIZE{ 300 };
void Shift(char*, int32_t, int32_t, int32_t);
void AddZeroStart(char*, int32_t);
void InputString(char*);
bool IsAllDigits(char*);
bool IsAllAlpha(char*);
void Reverse(char*);
void Task();
#endif