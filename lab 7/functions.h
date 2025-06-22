#ifndef HEADER
#define HEADER
#include <string>
#include <iostream>

void Task();


struct Palindrom {
    size_t start{};
    size_t length{};
    std::string word;
};

void SortStringArray(std::string*, size_t);
bool CompareWords(const std::string&, const std::string&);
void SortPalindromes(Palindrom*, size_t);
bool ComparePalindromes(const Palindrom&, const Palindrom&);
bool IsLatinLetter(char);
bool Is_palindrome(const std::string&);
std::string ProcessString(const std::string&);
#endif