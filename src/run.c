#include "solution.h"

int
main()
{
#define test(exp, ...)                               \
        do {                                         \
                int a[] = {__VA_ARGS__};             \
                int res = findLHS(a, ARRAY_SIZE(a)); \
                printf("res: %d\n", res);            \
                assert(exp == res);                  \
        } while (0)
        test(2, 1, 2);
}
