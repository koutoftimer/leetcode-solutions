#include "solution.h"

// 6 bytes is enough to store "10000" but 8 is better for alignment
typedef char(Rank)[8];

Rank* arena;
int arena_size;

static inline char*
rank_to_str(int value)
{
        if (value == 1) {
                return strdup("Gold Medal");
        }
        if (value == 2) {
                return strdup("Silver Medal");
        }
        if (value == 3) {
                return strdup("Bronze Medal");
        }
        char* buf = arena[arena_size++];
        sprintf(buf, "%d", value);
        return buf;
}

typedef struct {
        int value;
        int pos;
} Pair;

static int
cmp(int* a, int* b)
{
        return *b - *a;
}

char**
findRelativeRanks(int* score, int scoreSize, int* returnSize)
{
        Pair* sorted = malloc(scoreSize * sizeof(*sorted));
        for (int i = 0; i < scoreSize; ++i) {
                sorted[i] = (Pair){.value = score[i], .pos = i};
        }
        // sort by value (first 4 bytes of the Pair struct)
        qsort(sorted, scoreSize, sizeof(*sorted), (__compar_fn_t)cmp);
        char** res = malloc(scoreSize * sizeof(*res));
        arena      = malloc(scoreSize * sizeof(*arena));
        arena_size = 0;
        for (int i = 0; i < scoreSize; ++i) {
                res[sorted[i].pos] = rank_to_str(i + 1);
        }
        free(sorted);
        *returnSize = scoreSize;
        return res;
}
