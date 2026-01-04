#include "solution.h"

int
main()
{
#define test                                                                   \
        do {                                                                   \
                printf("Case %d\n=====\n", ++id);                              \
                int size;                                                      \
                char **res =                                                   \
                    findRestaurant(a, ARRAY_SIZE(a), b, ARRAY_SIZE(b), &size); \
                for (int i = 0; i < size; ++i) printf("'%s', ", res[i]);       \
                puts("\n");                                                    \
                free(res);                                                     \
        } while (0)
        int id = 0;
        // {
        //         char *a[] = {"Shogun", "Tapioca Express", "Burger King",
        //         "KFC"}; char *b[] = {"Piatti", "The Grill at Torrey Pines",
        //                      "Hungry Hunter Steakhouse", "Shogun"};
        //         test;
        // }
        {
                char *a[] = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
                char *b[] = {"KFC", "Shogun", "Burger King"};
                test;
        }
        // {
        //         char *a[] = {"happy", "sad", "good"};
        //         char *b[] = {"sad", "happy", "good"};
        //         test;
        // }
}
