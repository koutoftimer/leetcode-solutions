#include "solution.h"

int
binaryGap(int n)
{
        int max  = 0;
        int last = -1;
        int pos  = 0;
        while (n) {
                if (n & 1) {
                        if (last != -1 && pos - last > max) {
                                max = pos - last;
                        }
                        last = pos;
                }
                n /= 2;
                ++pos;
        }
        return max;
}
