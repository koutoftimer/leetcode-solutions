#include "solution.h"

int
sumFourDivisors(int* a, int size)
{
        int sum = 0;
        for (int i = 0; i < size; ++i) {
                int const number = a[i];
                int divisors[4]  = {1, number};
                int count        = 2;
                for (int div = 2; div * div <= number; ++div) {
                        if (number % div != 0) continue;
                        if (count == 4) goto dont_add;
                        divisors[count++] = div;
                        if (div * div != number)
                                divisors[count++] = number / div;
                }
                if (count != 4) continue;
                for (int j = 0; j < count; ++j) sum += divisors[j];
        dont_add:
        }
        return sum;
}
