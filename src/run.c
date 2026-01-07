#include "solution.h"

int
main()
{
#define test(a, b)                                         \
        printf("\nCase %d\n\n", ++id);                     \
        int size;                                          \
        char *s1   = strdup(a);                            \
        char *s2   = strdup(b);                            \
        char **res = uncommonFromSentences(s1, s2, &size); \
        for (int i = 0; i < size; ++i) {                   \
                printf("res[%d] = '%s'\n", i, res[i]);     \
                free(res[i]);                              \
        }                                                  \
        free(res);                                         \
        free(s1);                                          \
        free(s2);

        int id = 0;
        {
                test("this apple is sweet", "this apple is sour");
        }
}
