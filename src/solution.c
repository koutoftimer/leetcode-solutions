#include "solution.h"

char*
toLowerCase(char* s)
{
        char* res = s;
        while (*s) *s = tolower(*s), ++s;
        return res;
}
