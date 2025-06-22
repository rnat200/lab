#include "functions.h"

int main() {

	/*try {
		Task9();
	}

		catch (std::bad_array_new_length& e) {
			std::cerr <<"ERROR IN 1 TASK: " << e.what();
		}
		catch (std::system_error&e) {
			std::cerr <<"ERROR IN 1 TASK: " << e.what();
		}
		catch (std::exception &e) {
			std::cerr <<"ERROR IN 1 TASK: " << e.what();
		}*/

	try {
		Task11();
	}
		catch (std::bad_array_new_length& e) {
			std::cerr <<"ERROR IN 2 TASK: " << e.what();
		}
		catch (std::system_error& e) {
			std::cerr <<"ERROR IN 2 TASK: " << e.what();
		}
		catch (std::exception& e) {
			std::cerr <<"ERROR IN 2 TASK: "<< e.what();
		}

	return 0;
}

