#include "solution.h"

int**
imageSmoother(int** a, int rows, int* cols, int* returnSize,
              int** returnColumns)
{
        int average(int row, int col)
        {
                int sum   = a[row][col];
                int count = 1;
                for (int r = row - 1; r < row + 2; ++r) {
                        if (!(0 <= r && r < rows)) continue;
                        for (int c = col - 1; c < col + 2; ++c) {
                                if (r == row && c == col) continue;
                                if (!(0 <= c && c < *cols)) continue;
                                sum += a[r][c] & 0xFF;
                                count++;
                        }
                }
                return sum / count;
        }
        for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < *cols; ++col) {
                        a[row][col] |= average(row, col) << 8;
                }
        }
        for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < *cols; ++col) {
                        a[row][col] >>= 8;
                }
        }
        *returnColumns = cols;
        *returnSize    = rows;
        return a;
}
