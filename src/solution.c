#include "solution.h"

int primes[65];
int primes_len = 0;

[[gnu::constructor]]
static void
build_primes()
{
        primes[primes_len++] = 2;
        for (int i = 3; i * i <= 100000; i += 2) {
                for (int j = 0; j < primes_len; ++j) {
                        if (i % primes[j] == 0) goto not_prime;
                }
                primes[primes_len++] = i;
        not_prime:
        }
}

int
sumFourDivisors(int* a, int size)
{
        // asm("int3");
        int sum = 0;
        for (int i = 0; i < size; ++i) {
                int const number = a[i];
                int cur_sum      = 0;
                for (int j = 0;
                     j < primes_len && primes[j] * primes[j] < number;  //
                     ++j) {
                        int const prime = primes[j];
                        if (number % prime != 0) continue;
                        int const remainder = number / prime;
                        if (remainder == prime) continue;
                        if (cur_sum) goto dont_add;
                        cur_sum = 1 + prime + remainder + number;
                }
                sum += cur_sum;
        dont_add:
        }
        return sum;
}
