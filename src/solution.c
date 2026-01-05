#include "solution.h"

enum { CAPACITY = 50000 };

struct {
        int first;
        int freq;
}* count;

[[gnu::constructor]]
static void
init_count()
{
        count = malloc(CAPACITY * sizeof *count);
}

[[gnu::destructor]]
static void
free_count()
{
        free(count);
}

int
findShortestSubArray(int* a, int size)
{
        memset(count, 0, CAPACITY * sizeof *count);

        int max_freq = 0;
        int min_len  = size - 1;
        for (int i = 0; i < size; ++i) {
                int const index = a[i];
                count[index].freq++;
                if (!count[index].first) count[index].first = i + 1;

                int const len = i + 1 - count[index].first;
                if (count[index].freq > max_freq) {
                        max_freq = count[index].freq;
                        min_len  = len;

                } else if (count[index].freq == max_freq && len < min_len) {
                        min_len = len;
                }
        }

        return min_len + 1;
}
