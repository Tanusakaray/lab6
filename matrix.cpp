/*
Author: Tanushri Sakaray
KUID: 3080571
Date: 10/18/23
Lab: lab06
Last modified: 10/19/2023
Purpose: performs various operations on square matrices using functions and arrays
*/

#include <iostream>
#include <fstream>
#include <vector>

const int MAX_SIZE = 100;

bool readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE],int matrixB[MAX_SIZE][MAX_SIZE], int& size, const std::string& filename) {
    std::ifstream inputFile("matrix_input.txt"); 

    if (inputFile.is_open()) {
        if (!(inputFile >> size) || size <= 0 || size > MAX_SIZE) {
            std::cerr << "Error: Invalid matrix size." << std::endl;
            inputFile.close();
            return false;
        }

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (!(inputFile >> matrixA[i][j])) {
                    std::cerr << "Error: Invalid data in the file." << std::endl;
                    inputFile.close();
                    return false;
                }
            }
        }

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (!(inputFile >> matrixB[i][j])) {
                    std::cerr << "Error: Invalid data in the file for matrix B." << std::endl;
                    inputFile.close();
                    return false;
                }
            }
        }

        inputFile.close();
        std::cout << "Matrix read from " << filename << " successfully." << std::endl;
        return true;
    } else {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return false;
    }
}

void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE], resultProduct[MAX_SIZE][MAX_SIZE], resultDifference[MAX_SIZE][MAX_SIZE];
    int size;

    if (readMatrixFromFile(matrixA, matrixB,size, "matrix_input.txt")) {
        std::cout << "Matrix A:" << std::endl;
        printMatrix(matrixA, size);

        std::cout << "Matrix B:" << std::endl;
        printMatrix(matrixB, size);

        addMatrices(matrixA, matrixB, result, size);

        std::cout << "Matrix Sum (A + B):" << std::endl;
        printMatrix(result, size);

        multiplyMatrices(matrixA, matrixB, resultProduct, size);
        std::cout << "Matrix Product (A * B):" << std::endl;
        printMatrix(resultProduct, size);

        subtractMatrices(matrixA, matrixB, resultDifference, size);
        std::cout << "Matrix Difference (A - B):" << std::endl;
        printMatrix(resultDifference, size);
    }

    return 0;
}








