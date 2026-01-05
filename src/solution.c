#include "solution.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(a, b)                         \
        do {                               \
                __typeof(a) __tmp = a;     \
                a                 = b;     \
                b                 = __tmp; \
        } while (0)

typedef struct KthLargest {
        int* heap;
        int size;
} KthLargest;

KthLargest*
kthLargestCreate(int k, int* a, int size)
{
        int cmp(int* a, int* b) { return *a - *b; }
        qsort(a, size, sizeof *a, (__compar_fn_t)cmp);
        int* clone = malloc(k * sizeof *a);
        if (size > k) a += size - k;
        memcpy((size < k ? 1 : 0) + clone, a, MIN(size, k) * sizeof *a);
        if (size < k) clone[0] = INT_MIN;

        KthLargest* self = malloc(sizeof *self);
        self->heap       = clone;
        self->size       = k;

        return self;
}

static void
heap_down(KthLargest* self, int v)
{
        while (true) {
                int const left  = 2 * v + 1;
                int const right = 2 * v + 2;
                int min         = v;
                if (left < self->size && self->heap[left] < self->heap[min]) {
                        min = left;
                }
                if (right < self->size && self->heap[right] < self->heap[min]) {
                        min = right;
                }
                if (min != v) {
                        SWAP(self->heap[min], self->heap[v]);
                        v = min;
                } else {
                        break;
                }
        }
}

int
kthLargestAdd(KthLargest* self, int value)
{
        if (value > self->heap[0]) {
                self->heap[0] = value;
                heap_down(self, 0);
        }
        return self->heap[0];
}

void
kthLargestFree(KthLargest* self)
{
        free(self->heap);
}
