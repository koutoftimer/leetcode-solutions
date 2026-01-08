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
#define subtract_overlap(xx, yy)                         \
        if (0 <= xx && xx < xs && 0 <= yy && yy < *ys) { \
                total -= MIN(grid[x][y], grid[xx][yy]);  \
        }
                        subtract_overlap(x - 1, y);
                        subtract_overlap(x + 1, y);
                        subtract_overlap(x, y + 1);
                        subtract_overlap(x, y - 1);
                }
        }
        return total;
}
