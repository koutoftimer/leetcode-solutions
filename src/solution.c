#include "solution.h"

char
nextGreatestLetter(char* s, int size, char target)
{
        int low  = -1;
        int high = size;
        while (low + 1 < high) {
                int const mid = low + (high - low) / 2;
                if (s[mid] > target) {
                        high = mid;
                } else {
                        low = mid;
                }
        }
        return high == size ? *s : s[high];
}
