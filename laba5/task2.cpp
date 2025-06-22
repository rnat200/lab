#include "functions.h"
void Task9() {
	std::cout << "Task 9\n";
	int32_t choice;
	std::cout << "Choose a method to fill:\n";
	std::cout << "1. Manual\n";
	std::cout << "2. Random\n";
	std::cout << "Your choice: ";
	std::cin >> choice;

	Vector vec1;
	Vector vec2;

	switch (choice) {
	case 1: {
		InputVector(&vec1);
		InputVector(&vec2);
	} break;

	case 2: {
		double a{}, b{};
		InputBounds(a, b);
		CheckBounds(a, b);

		std::cout << "Enter vector length for vec1: ";
		std::cin >> vec1.length;
		if (vec1.length < 1) {
			throw std::invalid_argument("Invalid length");
		}
		vec1.vect = new double[vec1.length];
		FillVectorViaRandom(&vec1, a, b);
		OutVector(&vec1);

	
		std::cout << "Enter vector length for vec2: ";
		std::cin >> vec2.length;
		if (vec2.length < 1) {
			throw std::invalid_argument("Invalid length");
		}
		vec2.vect = new double[vec2.length];
		FillVectorViaRandom(&vec2, a, b);
		OutVector(&vec2);
	} break;

	default:
		throw std::invalid_argument("Invalid input choice");
	}

	double** mtr{ nullptr };
	CreateMtr(mtr, &vec1, &vec2);
	FillKoshiMtr(mtr, &vec1, &vec2);
	OutputMtr(mtr, &vec1, &vec2);
	OutSumInCol(mtr, &vec1, &vec2);

	Delete(&vec2);
	Delete(mtr, &vec1);  
	Delete(&vec1);

	system("pause");
	system("cls");
}

void InputVector(Vector* vec) {
	std::cout << "Enter vector length \n";
	
	std::cin >> vec->length;
	if (vec->length < 1) {
		throw std::invalid_argument("Invalid length\n");
	}
	vec->vect = new double[vec->length];
	std::cout << "Enter vector elem: \n";
	for (int32_t i{}; i < vec->length; ++i) {
		std::cin >> vec->vect[i];
	}
}

void CreateMtr(double**& mtr,Vector* vec1,Vector* vec2) {
	mtr = new double * [vec1->length];
	for (int32_t i = 0; i < vec1->length; ++i) {
		mtr[i] = new double[vec2->length];
	}
}

void FillKoshiMtr(double**& mtr, Vector* vec1, Vector* vec2) {
	for (int32_t i{}; i < vec1->length; ++i) {
		for (int32_t j{}; j < vec2->length; ++j) {
			mtr[i][j] = 1 / ((vec1->vect[i] + vec2->vect[j]));
		}
	}
}

void OutputMtr(double** mtr, Vector* vec1, Vector* vec2) {
	std::cout << "Matrix:" << std::endl;
	for (size_t i = 0; i < vec1->length; ++i) {
		for (size_t j = 0; j < vec2->length; ++j) {
			std::cout  << mtr[i][j]<<'\t' << std::setprecision(4);
		}
		std::cout << std::endl;
	}
}

void Delete(double** mtr, Vector* vec1) {
	for (int32_t i{}; i < vec1->length; ++i) {
		delete[] mtr[i];
	}
	delete[] mtr;
}

void Delete(Vector* vec) {
	delete[] vec->vect;
}

double SumInColumn(double** mtr, Vector* vec1, int32_t col) {
	double sum{};
	for (int32_t i{}; i < vec1->length; ++i) {
		sum += mtr[i][col];
	}
	return sum;
}

void OutSumInCol(double** mtr,Vector* vec1,Vector* vec2) {
	for (int32_t i{}; i < vec2->length; ++i) {
		std::cout << "Sum in " << i + 1 << " col is equal " << SumInColumn(mtr, vec1, i)<<std::endl;
	}
}



void InputBounds(double& lowerBound, double& upperBound) {
	std::cout << "Enter lower bound for dis(gen()): ";
	std::cin >> lowerBound;
	std::cout << "Enter upper bound for dis(gen()): ";
	std::cin >> upperBound;
}


void CheckBounds(double& upperBound, double& lowerBound) {
	if (lowerBound > upperBound) {
		std::swap(lowerBound, upperBound);
	}
}

void FillVectorViaRandom(Vector* vec, double lowerBound, double upperBound) {
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<double> dist(lowerBound, upperBound);

	for (int32_t i = 0; i < vec->length; ++i) {
		vec->vect[i] = dist(gen);
	}
}

void OutVector(Vector* vec) {
	for (int32_t i{}; i < vec->length; ++i) {
		std::cout << vec->vect[i]<<"\t";
	}
	std::cout << '\n';
}