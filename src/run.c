#include "solution.h"

int
main()
{
        int size = 0;

#define T(v, l, r) \
        &(struct TreeNode) { .val = v, .left = l, .right = r }
        int *res =
            findMode(T(1, T(1, 0, 0), T(2, T(2, NULL, NULL), NULL)), &size);
        printf("Res size: %d\n", size);
        free(res);
}
