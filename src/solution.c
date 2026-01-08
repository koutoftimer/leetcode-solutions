#include "solution.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
int
surfaceArea(int** grid, int xs, int* ys)
{
        int total = 0;
        for (int x = 0; x < xs; ++x) {
                for (int y = 0; y < *ys; ++y) {
                        if (!grid[x][y]) continue;
                        total += 2 + 4 * grid[x][y];
                        if (x > 0) total -= 2 * MIN(grid[x][y], grid[x - 1][y]);
                        if (y > 0) total -= 2 * MIN(grid[x][y], grid[x][y - 1]);
                }
        }
        return total;
}
