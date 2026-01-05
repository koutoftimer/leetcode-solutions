#include "solution.h"

static bool
palindrom(char *l, char *r)
{
        while (l < r) {
                if (*l++ != *r--) return false;
        }
        return true;
}

bool
validPalindrome(char *s)
{
        int len = strlen(s);
        char *l = s, *r = s + len - 1;
        for (; l < r; ++l, --r) {
                if (*l != *r) {
                        return palindrom(l + 1, r) || palindrom(l, r - 1);
                }
        }
        return true;
}
