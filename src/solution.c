#include "solution.h"

int
findLHS(int* a, int size)
{
        int cmp(int* a, int* b) { return *a - *b; }
        qsort(a, size, sizeof *a, (__compar_fn_t)cmp);
        int len = 0, prev_len = 0, max_len = len;
        int *cur = a, *prev = a;
        while (cur < a + size) {
                while (cur < a + size && *cur++ == *prev) {
                        ++len;
                }
                if (cur < a + size) {
                        if (len > max_len) max_len = len;
                        prev = cur;
                        len  = 0;
                }
        }
        return max_len;
}
