#include "solution.h"

int**
largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes)
{
        int const len   = strlen(s);
        int max_chunks  = (len + 2) / 3;
        int** res       = malloc(max_chunks * sizeof *res);
        int size        = 0;
        int (*arena)[2] = malloc(max_chunks * sizeof(*arena));
        int arena_size  = 0;
        char *l = s, *r = s;
        while (*r) {
                while (*r && *r == *l) ++r;
                if (r - l > 2) {
                        res[size]      = arena[arena_size++];
                        res[size][0]   = l - s;
                        res[size++][1] = r - s - 1;
                }
                l = r;
        }
        *returnSize        = size;
        *returnColumnSizes = malloc(size * sizeof *returnColumnSizes);
        for (int i = 0; i < size; ++i) (*returnColumnSizes)[i] = 2;
        return res;
}
