#include "solution.h"

double
findMaxAverage(int *a, int size, int k)
{
        int sum = 0;
        int i   = 0;
        for (; i < k; ++i) sum += a[i];
        int max = sum;
        for (; i < size; ++i) {
                sum = sum - a[i - k] + a[i];
                if (sum > max) max = sum;
        }
        return (double)max / k;
}
