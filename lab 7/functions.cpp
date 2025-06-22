#include "functions.h"
bool IsLatinLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool Is_palindrome(const std::string& s) {
    for (size_t i{}, j = s.length() - 1; i < j; ++i, --j) {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

bool CompareWords(const std::string& a, const std::string& b) {
    size_t min_len = std::min(a.length(), b.length());
    for (size_t i{}; i < min_len; ++i) {
        char a_char = a[i];
        char b_char = b[i];
        if (tolower(a_char) != tolower(b_char)) {
            return tolower(a_char) < tolower(b_char);
        }
        if (isupper(a_char) && islower(b_char)) {
            return true;
        }
        if (islower(a_char) && isupper(b_char)) {
            return false;
        }
    }
    return a.length() < b.length();
}

void SortStringArray(std::string* arr, size_t size) {
    for (size_t i {1}; i < size; ++i) {
        std::string key = arr[i];
        int j = static_cast<int>(i) - 1;
        while (j >= 0 && !CompareWords(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}



std::string ProcessString(const std::string& s) {
    if (s.empty()) {
        return s;
    }

    Palindrom* palindromes{ nullptr };
    size_t count{};
    size_t capacity{};

    size_t i{};
    while (i < s.length()) {
        if (IsLatinLetter(s[i])) {
            size_t start = i;
            std::string word;
            while (i < s.length() && IsLatinLetter(s[i])) {
                word += s[i];
                i++;
            }
            if (Is_palindrome(word)) {
                if (count >= capacity) {
                    size_t new_capacity;
                    if (capacity == 0) {
                        new_capacity = 1;
                    }
                    else {
                        new_capacity = capacity * 2;
                    }
                    Palindrom* temp = new Palindrom[new_capacity];
                    for (size_t j{}; j < count; j++) {
                        temp[j] = palindromes[j];
                    }
                    delete[] palindromes;
                    palindromes = temp;
                    capacity = new_capacity;
                }
                palindromes[count++] = { start, word.length(), word };
            }
        }
        else {
            i++;
        }
    }

    if (count == 0) {
        delete[] palindromes;
        return s;
    }

    std::string* sorted_words = new std::string[count];
    for (size_t j{}; j < count; j++) {
        sorted_words[j] = palindromes[j].word;
    }

    SortStringArray(sorted_words, count);
    

    std::string result;
    size_t current  {};
    for (size_t j{}; j < count; j++) {
        if (current < palindromes[j].start) {
            result += s.substr(current, palindromes[j].start - current);
        }
        result += sorted_words[j];
        current = palindromes[j].start + palindromes[j].length;
    }
    if (current < s.length()) {
        result += s.substr(current);
    }

    delete[] palindromes;
    delete[] sorted_words;
    return result;
}

void Task() {
    std::string input;
    std::getline(std::cin, input);
    std::string output = ProcessString(input);
    std::cout << output << std::endl;
}