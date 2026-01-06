#include "solution.h"

bool
isToeplitzMatrix(int** a, int rows, int* cols)
{
        bool matches(int row, int col)
        {
                int const original = a[row++][col++];
                while (row < rows && col < *cols) {
                        if (a[row][col] != original) {
                                return false;
                        }
                }
                return true;
        }
        int col = 0, row;
        for (row = 1; row < rows; ++row) {
                if (!matches(row, col)) return false;
        }
        row = 0;
        for (col = 0; col < *cols; ++col) {
                if (!matches(row, col)) return false;
        }
        return true;
}
