#include "solution.h"

bool
canPlaceFlowers(int* a, int size, int n)
{
        for (int i = 0; i < size; ++i) {
                int count = a[i];
                if (i - 1 >= 0) count += a[i - 1];
                if (i + 1 < size) count += a[i + 1];
                if (!count) {
                        a[i] = true;
                        n--;
                }
        }
        return n <= 0;
}
