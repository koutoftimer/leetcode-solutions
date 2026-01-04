#include "solution.h"

int
main()
{
#define test(exp, ...)                                       \
        do {                                                 \
                int a[] = {__VA_ARGS__};                     \
                int res = sumFourDivisors(a, ARRAY_SIZE(a)); \
                printf("res: %d\n", res);                    \
                assert(res == exp);                          \
        } while (0)
        test(32, 21, 4, 7);
        test(45, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        test(0, 81);
        test(10932, 7286, 18704, 70773, 8224, 91675);
}
