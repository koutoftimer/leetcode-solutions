#include "solution.h"

bool
checkRecord(char* s)
{
        int absent = 0;
        int late   = 0;
        while (*s) {
                char current = *s++;
                if (current == 'A') ++absent;
                late = current == 'L' ? late + 1 : 0;
                if (late == 3) return false;
        }
        return absent < 2;
}
