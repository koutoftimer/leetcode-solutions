#include <stdlib.h>

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
        int id                   = 0;
        // {
        //         char *a[] = {"Shogun", "Tapioca Express", "Burger King",
        //         "KFC"}; char *b[] = {"Piatti", "The Grill at Torrey Pines",
        //                      "Hungry Hunter Steakhouse", "Shogun"};
        //         test;
        // }
        // {
        //         char *a[] = {"Shogun", "Tapioca Express", "Burger King",
        //         "KFC"}; char *b[] = {"KFC", "Shogun", "Burger King"}; test;
        // }
        // {
        //         char *a[] = {"happy", "sad", "good"};
        //         char *b[] = {"sad", "happy", "good"};
        //         test;
        // }
        char allowed[26 * 2 + 2] = {' '};
        for (uint i = 1; i + 1 < ARRAY_SIZE(allowed); ++i) {
                allowed[i] = i <= 26 ? i + 'A' - 1 : i - 26 + 'a' - 1;
        }
        int const allowed_len = strlen(allowed);

        enum { BLOCK_SIZE = 32 };
        char arena[2001][BLOCK_SIZE] = {0};
        int arena_size               = 0;

        char *a[1000];
        char *b[1000];
        for (uint i = 0; i < 1000; ++i) {
                a[i] = arena[arena_size++];
                b[i] = arena[arena_size++];
                for (int j = 0; j < 30; ++j) {
                        a[i][j] = allowed[rand() % allowed_len];
                        b[i][j] = allowed[rand() % allowed_len];
                }
        }
        strcpy(b[0], a[0]);
        test;
}
