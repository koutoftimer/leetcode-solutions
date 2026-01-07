#include "solution.h"

static char*
next(char* s, char* it)
{
        int skip = 0;
        while (it >= s) {
                if (*it == '#') {
                        --it, ++skip;
                } else if (skip) {
                        --it, --skip;
                } else {
                        break;
                }
        }
        return it;
}
bool
backspaceCompare(char* s, char* t)
{
        int const s_len = strlen(s);
        int const t_len = strlen(t);
        char* s_it      = next(s, s + s_len - 1);
        char* t_it      = next(t, t + t_len - 1);
        while (s_it >= s && t_it >= t) {
                if (*s_it != *t_it) return false;
                s_it = next(s, s_it - 1);
                t_it = next(t, t_it - 1);
        }
        return s_it < s && t_it < t;
}
