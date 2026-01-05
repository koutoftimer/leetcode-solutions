#include "solution.h"

bool
hasAlternatingBits(uint n)
{
        return (0xAAAAAAAA >> __builtin_clz(n)) == n;
}
