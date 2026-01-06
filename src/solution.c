#include "solution.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
int
minCostClimbingStairs(int* cost, int size)
{
        for (int i = 2; i < size; ++i) {
                cost[i] += MIN(cost[i - 1], cost[i - 2]);
        }
        return MIN(cost[size - 1], cost[size - 2]);
}
