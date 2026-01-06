#include "solution.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
int
minCostClimbingStairs(int* cost, int size)
{
        int res[2] = {cost[0], cost[1]};
        for (int i = 2; i < size; ++i) {
                int const tmp = cost[i] + MIN(res[0], res[1]);
                res[0]        = res[1];
                res[1]        = tmp;
        }
        return MIN(res[0], res[1]);
}
