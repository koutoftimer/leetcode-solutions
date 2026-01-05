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
        int k;
} KthLargest;

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

static void
heap_up(KthLargest* self, int v)
{
        while (v > 0) {
                int const parent = (v - 1) / 2;
                if (self->heap[parent] > self->heap[v]) {
                        SWAP(self->heap[parent], self->heap[v]);
                        v = parent;
                } else {
                        break;
                }
        }
}

static void
heap_insert(KthLargest* self, int value)
{
        if (self->size < self->k) {
                self->heap[self->size++] = value;
                heap_up(self, self->size - 1);
        } else if (value > self->heap[0]) {
                self->heap[0] = value;
                heap_down(self, 0);
        }
}

KthLargest*
kthLargestCreate(int k, int* a, int size)
{
        KthLargest* self = malloc(sizeof *self);
        self->heap       = malloc(k * sizeof *a);
        self->size       = 0;
        self->k          = k;
        for (int i = 0; i < size; ++i) {
                heap_insert(self, a[i]);
        }
        return self;
}

int
kthLargestAdd(KthLargest* self, int value)
{
        heap_insert(self, value);
        return self->heap[0];
}

void
kthLargestFree(KthLargest* self)
{
        free(self->heap);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);

 * kthLargestFree(obj);
*/
