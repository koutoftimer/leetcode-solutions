#include "solution.h"

int**
floodFill(int** image, int rows, int* cols, int row, int col, int color,
          int* returnSize, int** returnColumnSizes)
{
        int const to_replace = image[row][col];
        void dfs(int row, int col)
        {
                if (!(0 <= row && row < rows && 0 <= col && col < *cols)) {
                        return;
                }
                if (image[row][col] != to_replace) {
                        return;
                }
                image[row][col] = color;
                dfs(row + 1, col);
                dfs(row - 1, col);
                dfs(row, col + 1);
                dfs(row, col - 1);
        }
        if (color != to_replace) dfs(row, col);
        *returnSize        = rows;
        *returnColumnSizes = cols;
        return image;
}
