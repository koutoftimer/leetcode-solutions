#include "solution.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

int
maximumProduct(int *a, int size)
{
        int cmp(int *a, int *b) { return *a - *b; }
        qsort(a, size, sizeof *a, (__compar_fn_t)cmp);
        int variations[] = {
            a[0] * a[1] * a[2],
            a[0] * a[1] * a[size - 1],
            a[0] * a[size - 1] * a[size - 2],
            a[size - 1] * a[size - 2] * a[size - 3],
        };
        int max = variations[0];
        for (uint i = 1; i < ARRAY_SIZE(variations); ++i) {
                if (max < variations[i]) max = variations[i];
        }
        return max;
}
