//14
#include "functions.h"

int main() {
	try {
		Task();
	}
	catch (std::runtime_error& e) {
		std::cout << "Runtime error: " << e.what();
	}
	catch (std::system_error &e) {
		std::cout <<"System error: "<< e.what();
	}
	return 0;
}