#include "solution.h"

static inline int
min(int a, int b)
{
        if (a < b) return a;
        return b;
}

static inline int
max(int a, int b)
{
        if (a > b) return a;
        return b;
}

#define SWAP(a, b)                         \
        do {                               \
                __typeof(a) __tmp = a;     \
                a                 = b;     \
                b                 = __tmp; \
        } while (0)

int
maxDotProduct(int* a, int a_len, int* b, int b_len)
{
        // we want B to be longer for better cache utilization
        if (a_len > b_len) return maxDotProduct(b, b_len, a, a_len);

        int prev_mem[500], current_mem[500];           // allocate on the stack
        int *prev = prev_mem, *current = current_mem;  // decay into pointer

        current[0] = a[0] * b[0];
        for (uint16_t j = 1; j != b_len; ++j) {
                current[j] = max(current[j - 1], a[0] * b[j]);
        }

        for (uint16_t i = 1; i != a_len; ++i) {
                SWAP(current, prev);

                int const ai = a[i];
                current[0]   = max(prev[0], ai * b[0]);
                for (uint16_t j = 1; j != b_len; ++j) {
                        int const option1 = ai * b[j];
                        int const option2 = prev[j - 1] + option1;
                        int const option3 = current[j - 1];
                        int const option4 = prev[j];
                        // reduce amount of comparisons
                        current[j] =
                            max(max(option1, option2), max(option3, option4));
                }
        }

        return current[b_len - 1];
}
