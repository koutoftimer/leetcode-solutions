#include "solution.h"

char*
reverseWords(char* s)
{
        char* res = s;
        while (*s) {
                char *l = s, *r = strchr(s, ' ');
                while (l + 1 < r) {
                        char tmp = *l;
                        *l++     = *(--r);
                        *r       = tmp;
                }
                s = r + !!*r;
        }
        return res;
}
