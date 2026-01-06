#include "solution.h"

int
findMiddleIndex(int* a, int size)
{
        // build partial sums inplace
        for (int i = 1; i < size; ++i) {
                a[i] += a[i - 1];
        }
        for (int i = 0; i < size; ++i) {
                int const left  = i ? a[i - 1] : 0;
                int const right = a[size - 1] - a[i];
                if (left == right) return i;
        }
        return -1;
}
