#include <iostream>

const int MAX_SIZE = 100;

void matrixMultiply(int mat1[][MAX_SIZE], int mat2[][MAX_SIZE], int result[][MAX_SIZE],int rows1, int cols1, int cols2)
{
    for (int i = 0; i < rows1; ++i) 
    {
        for (int j = 0; j < cols2; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() 
{
    int rows1, cols1, rows2, cols2;
    std::cout << "Enter the number of rows and columns for matrix 1: ";
    std::cin >> rows1 >> cols1;

    std::cout << "Enter the number of rows and columns for matrix 2: ";
    std::cin >> rows2 >> cols2;

    if (cols1 != rows2) 
    {
        std::cerr << "Error: Matrix multiplication not possible. Columns of matrix 1 must be equal to rows of matrix 2." << std::endl;
        return 1;
    }

    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];

    std::cout << "Enter elements of matrix 1:" << std::endl;
    for (int i = 0; i < rows1; ++i)
    {
        for (int j = 0; j < cols1; ++j) 
        {
            std::cin >> matrix1[i][j];
        }
    }

    std::cout << "Enter elements of matrix 2:" << std::endl;
    for (int i = 0; i < rows2; ++i) 
    {
        for (int j = 0; j < cols2; ++j) 
        {
            std::cin >> matrix2[i][j];
        }
    }

    int result[MAX_SIZE][MAX_SIZE];
    matrixMultiply(matrix1, matrix2, result, rows1, cols1, cols2);

    std::cout << "Resultant Matrix:" << std::endl;
    for (int i = 0; i < rows1; ++i) 
    {
        for (int j = 0; j < cols2; ++j) 
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
