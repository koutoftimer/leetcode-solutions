#include "solution.h"

int
search(int* a, int size, int target)
{
        int low  = -1;
        int high = size;
        while (low + 1 < high) {
                int mid = low + (high - low) / 2;
                if (target <= a[mid]) {
                        high = mid;
                } else {
                        low = mid;
                }
        }
        return high < size && a[high] == target ? high : -1;
}
