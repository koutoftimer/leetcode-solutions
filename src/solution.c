#include "solution.h"

int
dominantIndex(int* a, int size)
{
        int l = 0, r = 1;
        if (a[r] < a[l]) {
                int tmp = l;
                l       = r;
                r       = tmp;
        }
        for (int i = 2; i < size; ++i) {
                if (a[i] > a[r]) {
                        l = r;
                        r = i;
                } else if (a[i] > a[l]) {
                        l = i;
                }
        }
        return a[r] >= 2 * a[l] ? r : -1;
}
