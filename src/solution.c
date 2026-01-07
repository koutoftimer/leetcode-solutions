#include "solution.h"

int**
transpose(int** matrix, int rows, int* cols, int* returnSize,
          int** returnColumnSizes)
{
        int** res = malloc(*cols * sizeof *res);
        assert(res);
        for (int col = 0; col < *cols; ++col) {
                res[col] = malloc(rows * sizeof **res);
                assert(res[col]);
        }
        for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < *cols; ++col) {
                        res[col][row] = matrix[row][col];
                }
        }
        *returnSize        = *cols;
        *returnColumnSizes = malloc(*cols * sizeof *cols);
        assert(*returnColumnSizes);
        for (int i = 0; i < *cols; ++i) (*returnColumnSizes)[i] = rows;
        return res;
}
