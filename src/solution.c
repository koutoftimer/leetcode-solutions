#include "solution.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

int
maximumProduct(int *a, int size)
{
        int count[2005] = {0};
        for (int i = 0; i < size; ++i) {
                count[a[i] + 1000]++;
        }
        for (int n = 3, i = 0; n && i < ARRAY_SIZE(count); ++i) {
                while (n && count[i]) {
                        a[3 - n] = i - 1000;
                        --n;
                        --count[i];
                }
        }
        for (int n = 3, i = ARRAY_SIZE(count) - 1; n && i >= 0; --i) {
                while (n && count[i]) {
                        a[size - 1 + n - 3] = i - 1000;
                        --n;
                        --count[i];
                }
        }
        int variations[] = {
            a[0] * a[1] * a[2],
            a[0] * a[1] * a[size - 1],
            a[0] * a[size - 1] * a[size - 2],
            a[size - 1] * a[size - 2] * a[size - 3],
        };
        int max = variations[0];
        for (uint i = 1; i < ARRAY_SIZE(variations); ++i) {
                if (max < variations[i]) max = variations[i];
        }
        return max;
}
