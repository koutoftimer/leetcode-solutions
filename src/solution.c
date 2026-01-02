#include "solution.h"

int repeatedNTimes(int* a, int numsSize) {
        for (int i = 2; i < numsSize; ++i) {
                if (a[i-2] == a[i] || a[i-1] == a[i]) return a[i];
        }
        return a[0];
}
