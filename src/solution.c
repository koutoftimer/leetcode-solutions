#include "solution.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

char*
reverseStr(char* res, int k)
{
        char* s = res;
        while (*s) {
                int len = strlen(s);
                char *l = s, *r = s + MIN(len, k) - 1;
                while (l < r) {
                        char tmp = *l;
                        *l++     = *r;
                        *r--     = tmp;
                }
                s += MIN(2 * k, len);
        }
        return res;
}
