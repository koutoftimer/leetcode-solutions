#include "solution.h"

int
main()
{
#define test(n, exp)                                         \
        do {                                                 \
                int res = numOfWays(n);                      \
                printf("res: %d\n", res);                    \
                assert(res == exp && "n = " #n " != " #exp); \
        } while (0);
        test(1, 12);
        test(2, 54);
        test(3, 246);
        test(4, 1122);
        test(10, 10107954);
        test(5000, 30228214);
        // for (int i = 0; i < 5001; ++i) {
        //         printf("%d,\n", numOfWays(i));
        // }
}
