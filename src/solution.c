#include "solution.h"

static void
reduce(char* s)
{
        char *in = s, *out = s;
        for (; *in; ++in) {
                if (*in == '#') {
                        out -= out > s;
                } else {
                        *out++ = *in;
                }
        }
        *out = '\0';
}
bool
backspaceCompare(char* s, char* t)
{
        reduce(s);
        reduce(t);
        return strcmp(s, t) == 0;
}
