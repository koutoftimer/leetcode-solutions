#include "solution.h"

int
findLHS(int* a, int size)
{
        // asm("int3");
        int cmp(int* a, int* b) { return *a - *b; }
        qsort(a, size, sizeof *a, (__compar_fn_t)cmp);
        int left = 0, right = 0;
        int prev_value, prev_count;
        int max = 0;
        while (right < size) {
                while (right < size && a[left] == a[right]) ++right;
                int const count = right - left;
                if (left && abs(prev_value - a[left]) == 1 &&
                    prev_count + count > max) {
                        max = prev_count + count;
                }
                prev_value = a[left];
                prev_count = count;
                left       = right;
        }
        return max;
}
