#include "solution.h"

long long
maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize)
{
        long long sum = 0;
        int min       = INT_MAX;
        int negatives = 0;
        for (int i = 0; i < matrixSize; ++i) {
                for (int j = 0; j < matrixSize; ++j) {
                        int const value = matrix[i][j];
                        sum += abs(value);
                        negatives ^= 1;
                        if (abs(value) < min) min = abs(value);
                }
        }
        if (negatives) {
                sum -= 2 * min;
        }
        return sum;
}
