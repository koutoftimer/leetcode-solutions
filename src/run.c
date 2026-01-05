#include "solution.h"

int
main()
{
#define test                                        \
        printf("\nCase: %d\n\n", ++id);             \
        int res = search(a, ARRAY_SIZE(a), target); \
        printf("res: %d\n", res);                   \
        assert(res == exp);

        int id = 0;
        {
                int a[]    = {-1, 0, 3, 5, 9, 12};
                int target = 9;
                int exp    = 4;
                test
        }
        {
                int a[]    = {-1, 0, 3, 5, 9, 12};
                int target = 13;
                int exp    = -1;
                test
        }
}
