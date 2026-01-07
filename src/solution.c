#include "solution.h"

int*
numberOfLines(int* widths, int widthsSize, char* s, int* returnSize)
{
        int* res   = malloc(2 * sizeof *res);
        int* lines = &res[0];
        int* width = &res[1];
        *lines = 1, *width = 0;
        for (; *s; ++s) {
                int const size = widths[*s - 'a'];
                if (*width + size <= 100) {
                        *width += size;
                } else {
                        *width = size;
                        (*lines)++;
                }
        }
        *returnSize = 2;
        return res;
}
