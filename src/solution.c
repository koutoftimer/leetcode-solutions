#include "solution.h"

int
findLHS(int* a, int size)
{
        int cmp(int* a, int* b) { return *a - *b; }
        qsort(a, size, sizeof *a, (__compar_fn_t)cmp);
        struct {
                int value;
                int count;
        }* stack       = malloc(size * sizeof(*stack));
        int stack_size = 0;
        for (int i = 0; i < size; ++i) {
                if (stack_size && stack[stack_size - 1].value == a[i]) {
                        stack[stack_size - 1].count += 1;
                } else {
                        stack[stack_size].value   = a[i];
                        stack[stack_size++].count = 1;
                }
        }
        int max = 0;
        for (int i = 1; i < stack_size; ++i) {
                int const diff = stack[i].value - stack[i - 1].value;
                int const len  = stack[i].count + stack[i - 1].count;
                if (abs(diff) == 1 && len > max) max = len;
        }
        return max;
}
