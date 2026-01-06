#include "solution.h"

static bool
is_self_dividing(int const number)
{
        int n = number;
        while (n) {
                int const digit = n % 10;
                n /= 10;
                if (!digit || number % digit) return false;
        }
        return true;
}

int*
selfDividingNumbers(int left, int right, int* returnSize)
{
        int* res = malloc((right - left + 1) * sizeof *res);
        int size = 0;
        for (int number = left; number <= right; ++number) {
                if (is_self_dividing(number)) res[size++] = number;
        }
        *returnSize = size;
        return res;
}
