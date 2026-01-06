#include "solution.h"

static int
is_prime(int const value)
{
        switch (value) {
        case 2:
        case 3:
        case 5:
        case 7:
        case 11:
        case 13:
        case 17:
        case 19:
                return true;
        }
        return false;
}

int
countPrimeSetBits(int left, int right)
{
        int count = 0;
        for (int i = left; i <= right; ++i) {
                if (is_prime(__builtin_popcount(i))) count++;
        }
        return count;
}
