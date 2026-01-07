#include "solution.h"

int*
shortestToChar(char* s, char c, int* returnSize)
{
        int len    = strlen(s);
        int* res   = malloc(len * sizeof *res);
        int prev_s = -1;
        for (int i = 0; i < len; ++i) {
                if (s[i] == c) prev_s = i;
                res[i] = INT_MAX;
                if (prev_s != -1) {
                        res[i] = i - prev_s;
                }
        }
        prev_s = -1;
        for (int i = len - 1; i >= 0; --i) {
                if (s[i] == c) prev_s = i;
                if (prev_s != -1 && prev_s - i < res[i]) {
                        res[i] = prev_s - i;
                }
        }
        *returnSize = len;
        return res;
}
