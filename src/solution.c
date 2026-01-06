#include "solution.h"

bool
isToeplitzMatrix(int** a, int rows, int* cols)
{
        int const len = *cols - 1;
        for (int row = 1; row < rows; ++row) {
                if (memcmp(a[row - 1], &a[row][1], len * sizeof **a) != 0)
                        return false;
        }
        return true;
}
