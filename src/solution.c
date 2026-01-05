#include "solution.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
int
countBinarySubstrings(char* s)
{
        int sum      = 0;
        int prev_len = 0;
        char *l = s, *r = s;
        while (*r) {
                while (*r && *l == *r) r++;
                int const len = r - l;
                l             = r;
                if (prev_len) {
                        sum += MIN(len, prev_len);
                }
                prev_len = len;
        }
        return sum;
}
