#include "solution.h"

typedef struct KthLargest {
        int* a;
        int size;
        int k;
} KthLargest;

KthLargest*
kthLargestCreate(int k, int* a, int size)
{
        int const capacity = k > size ? k : size;
        int* clone         = malloc(capacity * sizeof *a);
        memcpy(clone, a, size * sizeof *a);

        int cmp(int* a, int* b) { return *b - *a; }
        qsort(clone, size, sizeof *clone, (__compar_fn_t)cmp);

        KthLargest* self = malloc(sizeof *self);
        self->a          = clone;
        self->size       = size;
        self->k          = k;
        return self;
}

static int
lower_bound(KthLargest* self, int value)
{
        if (self->size == 0) return 0;
        int l = -1;
        int r = self->size;
        while (l + 1 < r) {
                int mid = l + (r - l) / 2;
                if (value >= self->a[mid]) {
                        r = mid;
                } else {
                        l = mid;
                }
        }
        return r;
}

int
kthLargestAdd(KthLargest* self, int value)
{
        int insertion = lower_bound(self, value);

        if (self->size < self->k) {
                self->size++;
        }
        if (insertion < self->size) {
                int const len = self->size - insertion - 1;
                memmove(self->a + insertion + 1, self->a + insertion,
                        len * sizeof *self->a);
        }
        if (insertion < self->size) {
                self->a[insertion] = value;
        }

        return self->a[self->k - 1];
}

void
kthLargestFree(KthLargest* self)
{
        free(self->a);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/
