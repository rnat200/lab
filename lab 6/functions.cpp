#include "functions.h"
     
void Shift(char* str, int32_t posIndex, int32_t shiftSize, int32_t strsize) {
	
	if (posIndex < 0 || posIndex >= strsize || shiftSize <= 0) {
		return;
	}
	for (int32_t i{ strsize }; i >= posIndex; --i) {
		str[i + shiftSize] = str[i];  
	}
	for (int32_t i { posIndex }; i < posIndex + shiftSize; ++i) {
		str[i] = ' ';
	}
}    
  
void AddZeroStart(char* str, int32_t zerocount) {
	int32_t len = static_cast<int32_t>(strlen(str));
	if (zerocount + len >= MAX_STRING_SIZE) {
		return;
	}
	for (int32_t i = len - 1; i >= 0; --i) {
		str[i + zerocount] = str[i];
	}
	for (int32_t i = 0; i < zerocount; ++i) {
		str[i] = '0';
	}
	str[len + zerocount] = '\0';
}
      
void InputString(char* str) {
	do {
		std::cout << "Input your string (Max string size 299 symbols) \n";
		std::cin.getline(str, MAX_STRING_SIZE);
	} while (strlen(str) == 0);
}    
    
bool IsAllDigits(char* str) {
	bool allDigits{ true };
	for (int32_t i{ 0 }; str[i] != '\0'; ++i) {
		if (!isdigit(str[i])) {
			allDigits = false;
		}
	}
	return allDigits;
}

bool IsAllAlpha(char*str) {
	bool allAlpha{true};
	for (int32_t i{ }; str[i] != '\0'; ++i) {
		if (!isalpha(str[i])) {
			allAlpha = false;
		}
	}
	return allAlpha;
}   
     
void Task() {
	char newStr[MAX_STRING_SIZE]="";
	char str[MAX_STRING_SIZE];
	char delim[] = " `!@#$%^&*()__+}{|\":?></~¹;%:?'\t\n";
	InputString(str);
	int32_t length{ static_cast<int32_t>(strlen(str)) };
	char* token = strtok(str, delim);
	
	while (token != NULL) {
		char tempToken[MAX_STRING_SIZE];
		strcpy(tempToken, token);
		if (strlen(token) < 5 && IsAllDigits(tempToken)) {
			int32_t zerocount{ 5 - static_cast<int32_t>(strlen(tempToken))};
			AddZeroStart(tempToken, zerocount);
		}else if (strlen(tempToken) < 5 && IsAllAlpha(tempToken)) {
			Reverse(tempToken);
		}
	 
		strcat(newStr, tempToken);
		strcat(newStr," ");
		token = strtok(NULL, delim);
	}
	std::cout << newStr;

}     
      
      
void Reverse(char* str) {
	int32_t len{static_cast<int32_t> (strlen(str)) };
	for (int32_t i{}; i < len / 2; ++i) {
		std::swap(str[i], str[len- i-1]);
	}
}   
    