#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

// Function prototypes
void readMatrixFromFile(int matrix1[MAX_SIZE][MAX_SIZE],int matrix2[MAX_SIZE][MAX_SIZE], int &size, const char *filename);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int size;

    // Read the matrices from the file
    readMatrixFromFile(matrix1, matrix2, size, "matrix_input.txt");
    

    std::cout << "Harrison Wendt" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    // Display Matrix A
    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrix1, size);

    // Display Matrix B
    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrix2, size);

    // Perform matrix operations
    addMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(result, size);

    multiplyMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(result, size);

    subtractMatrices(matrix1, matrix2, result, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(result, size);

    return 0;
}

// Function to read matrix data from a file
void readMatrixFromFile(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int &size, const char *filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Unable to open the file " << filename << std::endl;
        exit(1);
    }

    file >> size; // Read the size of the square matrix
    //matrix A
    for (int i = 0; i < (size); ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            file >> matrix1[i][j];
        }
    }
    //matrix B
    for (int i = 0; i < (size); ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            file >> matrix2[i][j];
        }
    }
}


// Function to print a matrix
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices
void addMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) 
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}
