#include "solution.h"

int
main()
{
        int id = 0;

#define test(exp, a, b)                        \
        do {                                   \
                printf("\nCase %d\n\n", ++id); \
                bool res = rotateString(a, b); \
                printf("\tres: %d\n", res);    \
                assert(res == exp);            \
        } while (0)
        test(true, "abcde", "cdeab");
        test(true, "defdefdefabcabcdef", "defdefabcabcdefdef");
}
