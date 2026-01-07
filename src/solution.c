#include "solution.h"

static int
find(int* a, int a_len, int needle)
{
        int low  = -1;
        int high = a_len;
        while (low + 1 < high) {
                int mid = low + (high - low) / 2;
                if (a[mid] >= needle) {
                        high = mid;
                } else {
                        low = mid;
                }
        }
        return high;
}

int*
fairCandySwap(int* a, int a_len, int* b, int b_len, int* returnSize)
{
        int cmp(int* a, int* b) { return *a - *b; }
        qsort(a, a_len, sizeof *a, (__compar_fn_t)cmp);
        int a_total = 0;
        int b_total = 0;
        for (int i = 0; i < a_len; ++i) {
                a_total += a[i];
        }
        for (int i = 0; i < b_len; ++i) {
                b_total += b[i];
        }
        int* res    = malloc(2 * sizeof *res);
        *returnSize = 2;
        for (int i = 0; i < b_len; ++i) {
                int const complement = (a_total - b_total) / 2 + b[i];
                int const index      = find(a, a_len, complement);
                if (index < a_len && a[index] == complement) {
                        res[0] = a[index];
                        res[1] = b[i];
                        return res;
                }
        }
        assert("unreachable");
        abort();
}
