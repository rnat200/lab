// задача 17
#include "functions.h"


int main() {
    
   
    try {
        Task();
    }
    catch (std::exception&e) {
        std::cout << "Unable to solve the problem: " <<e.what() << std::endl;
    }
    return 0;
}