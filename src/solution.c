#include "solution.h"

bool
detectCapitalUse(char* s)
{
        int len             = strlen(s);
        int capitals        = 0;
        bool first_capital  = *s < 'a';
        while (*s) capitals += *s < 'a';

        return capitals == 0 || capitals == len ||
               (first_capital && capitals == 1);
}
