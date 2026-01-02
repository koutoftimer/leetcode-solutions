#include "solution.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static int
cmp(int* a, int* b)
{
        return *a - *b;
}

int
distributeCandies(int* candyType, int candyTypeSize)
{
        qsort(candyType, candyTypeSize, sizeof *candyType, (__compar_fn_t)cmp);
        int unique = 1;
        for (int i = 1; i < candyTypeSize; ++i) {
                unique += candyType[i] != candyType[i - 1];
        }
        return MIN(unique, candyTypeSize / 2);
}
