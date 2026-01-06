#include "solution.h"

enum { VISITED = 1 << 16 };
int**
floodFill(int** image, int rows, int* cols, int row, int col, int color,
          int* returnSize, int** returnColumnSizes)
{
        int** res = malloc(rows * sizeof *res);
        for (int i = 0; i < rows; ++i) {
                res[i] = malloc(*cols * sizeof **res);
                memcpy(res[i], image[i], *cols * sizeof **res);
        }
        int const to_replace = image[row][col];
        void dfs(int row, int col)
        {
                if (!(0 <= row && row < rows && 0 <= col && col < *cols)) {
                        return;
                }
                if (res[row][col] != to_replace || image[row][col] & VISITED) {
                        return;
                }

                res[row][col] = color;
                image[row][col] |= VISITED;

                dfs(row + 1, col);
                dfs(row - 1, col);
                dfs(row, col + 1);
                dfs(row, col - 1);
        }
        dfs(row, col);
        *returnSize        = rows;
        *returnColumnSizes = malloc(rows * sizeof *returnColumnSizes);
        memcpy(*returnColumnSizes, cols, rows * sizeof *cols);
        return res;
}
