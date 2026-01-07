#include "solution.h"

int
projectionArea(int** grid, int n, int* ys)
{
        int xy_projection = 0;
        for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                        xy_projection += (bool)grid[x][y];
                }
        }
        int xz_projection = 0;
        for (int x = 0; x < n; ++x) {
                int max = grid[x][0];
                for (int y = 1; y < n; ++y) {
                        if (grid[x][y] > max) max = grid[x][y];
                }
                xz_projection += max;
        }
        int yz_projection = 0;
        for (int y = 0; y < n; ++y) {
                int max = grid[0][y];
                for (int x = 1; x < n; ++x) {
                        if (grid[x][y] > max) max = grid[x][y];
                }
                yz_projection += max;
        }
        return xy_projection + xz_projection + yz_projection;
}
