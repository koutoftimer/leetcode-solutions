#include "solution.h"

int**
flipAndInvertImage(int** image, int rows, int* cols, int* returnSize,
                   int** returnColumnSizes)
{
        int** res = malloc(rows * sizeof *res);
        for (int row = 0; row < rows; ++row) {
                res[row] = malloc(*cols * sizeof **res);
                int size = 0;
                for (int col = *cols - 1; col >= 0; --col) {
                        res[row][size++] = image[row][col] ^ 1;
                }
        }
        *returnSize        = rows;
        *returnColumnSizes = malloc(rows * sizeof *returnColumnSizes);
        memcpy(*returnColumnSizes, cols, rows * sizeof *cols);
        return res;
}
