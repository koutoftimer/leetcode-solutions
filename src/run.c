#include "solution.h"

int
main()
{
#define test                                                                \
        do {                                                                \
                printf("\n\nCase: %d\n\n", ++id);                           \
                KthLargest* obj = kthLargestCreate(k, a, ARRAY_SIZE(a));    \
                for (uint i = 0; i < ARRAY_SIZE(values); ++i) {             \
                        int ret = kthLargestAdd(obj, values[i]);            \
                        printf("add: %d, result: %d, ret: %d\n", values[i], \
                               results[i], ret);                            \
                        assert(ret == results[i]);                          \
                }                                                           \
                kthLargestFree(obj);                                        \
                free(obj);                                                  \
        } while (0)

        int id = 0;
        {
                int k         = 3;
                int a[]       = {4, 5, 8, 2};
                int values[]  = {3, 5, 10, 9, 4};
                int results[] = {4, 5, 5, 8, 8};
                test;
        }
        {
                int k         = 1;
                int a[]       = {};
                int values[]  = {3, 5, 10, 9, 4};
                int results[] = {3, 5, 10, 10, 10};
                test;
        }
        {
                int k         = 2;
                int a[]       = {0};
                int values[]  = {-1, 1, -2, -4, 3};
                int results[] = {-1, 0, 0, 0, 1};
                test;
        }
        {
                int k         = 3;
                int a[]       = {5, -1};
                int values[]  = {2, 1, -1, 3, 4};
                int results[] = {-1, 1, 1, 2, 3};
                test;
        }
}
