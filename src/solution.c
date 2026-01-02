#include "solution.h"

static int
cmp(int *a, int *b)
{
        return *a - *b;
}

int
arrayPairSum(int *a, int size)
{
        qsort(a, size, sizeof *a, (__compar_fn_t)cmp);
}
