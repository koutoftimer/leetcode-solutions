#include "solution.h"

int
main()
{
        int a[] = {1, 1};
        int b[] = {2, 2};
        int size;
        int *res = fairCandySwap(a, ARRAY_SIZE(a), b, ARRAY_SIZE(b), &size);
        printf("res[0]: %d, res[1]: %d\n", res[0], res[1]);
        free(res);
}
