#include "solution.h"

int
findLengthOfLCIS(int* a, int size)
{
        int len = 1, max = len;
        for (int i = 1; i < size; ++i) {
                if (a[i] > a[i - 1]) {
                        len++;
                        if (len > max) max = len;
                } else {
                        len = 1;
                }
        }
        return max;
}
