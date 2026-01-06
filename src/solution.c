#include "solution.h"

bool
isOneBitCharacter(int* bits, int bitsSize)
{
        if (bitsSize == 1) return true;
        if (bitsSize == 0) return false;
        if (bits[0] == 0) return isOneBitCharacter(bits + 1, bitsSize - 1);
        return isOneBitCharacter(bits + 2, bitsSize - 2);
}
