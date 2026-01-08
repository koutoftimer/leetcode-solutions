#include "solution.h"

enum { CAPACITY = (int)1e5, BUCKETS = (CAPACITY + 31) / 32 + 1 };

uint* bit_set;
#define bit_set_assert_boundaries(v) assert(v >= 1), assert(v <= CAPACITY)
#define bit_set_index(v) (bit_set_assert_boundaries(v), (v) / 32)
#define bit_set_mask(v) (bit_set_assert_boundaries(v), 1u << (v) % 32)
#define bit_set_set(v) bit_set[bit_set_index(v)] |= bit_set_mask(v)
#define bit_set_contains(v) (bit_set[bit_set_index(v)] & bit_set_mask(v))

int*
fairCandySwap(int* a, int a_len, int* b, int b_len, int* returnSize)
{
        memset(bit_set, 0, BUCKETS * sizeof *bit_set);
        int a_total = 0;
        int b_total = 0;
        for (int i = 0; i < a_len; ++i) {
                a_total += a[i];
                bit_set_set(a[i]);
        }
        for (int i = 0; i < b_len; ++i) {
                b_total += b[i];
        }
        int* res    = malloc(2 * sizeof *res);
        *returnSize = 2;
        for (int i = 0; i < b_len; ++i) {
                int const complement = (a_total - b_total) / 2 + b[i];
                if (complement > 0 && complement <= 1e5 &&
                    bit_set_contains(complement)) {
                        res[0] = complement;
                        res[1] = b[i];
                        return res;
                }
        }
        assert("unreachable");
        abort();
}

[[gnu::constructor]]
static void
malloc_count()
{
        bit_set = malloc(BUCKETS * sizeof *bit_set);
}

[[gnu::destructor]]
static void
free_cont()
{
        free(bit_set);
}
