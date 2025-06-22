#ifndef HEADER
#define HEADER
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <stdexcept>
#include <string>
#include <cstdint>


struct Vector {
    int32_t length{};
    double* vect{ nullptr };
};

void OutSumInCol(double**, Vector*, Vector*);
void Task9();
double SumInColumn(double**, Vector*, int32_t);
void CreateMtr(double**&, Vector*, Vector*);
void InputVector(Vector*);
void FillKoshiMtr(double**&, Vector*, Vector*);
void OutputMtr(double**, Vector*, Vector*);
void Delete(Vector*);
void Delete(double**, Vector*);
void InputBounds(double&, double&);
void FillVectorViaRandom(Vector*, double, double);
void OutVector(Vector*);
void CheckBounds(double&, double&);


void Task11();
int32_t** CreateSpiralMatrix(int16_t size);
int64_t CalculateLowerRightTriangleSum(int32_t** matrix, int16_t size);
void PrintMatrix(int32_t** matrix, int16_t size);
void DeleteMatrix(int32_t** matrix, int16_t size);



#endif