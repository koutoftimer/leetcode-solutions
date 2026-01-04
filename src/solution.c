#include "solution.h"

char**
findRestaurant(char** a, int a_len, char** b, int b_len, int* returnSize)
{
        char** res = malloc((a_len > b_len ? b_len : a_len) * sizeof *res);
        int size   = 0;
        int sum    = a_len + b_len;
        for (int i = 0; i < a_len; ++i) {
                for (int j = 0; j < b_len; ++j) {
                        if (i + j > sum || strcmp(a[i], b[j]) != 0) continue;
                        if (i + j < sum) {
                                sum  = i + j;
                                size = 0;
                        }
                        res[size++] = a;
                }
        }
        *returnSize = size;
        return res;
}
