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
        int sum = 0;
        for (int i = 0; i < size; ++i) {
                int number = a[i];
                struct Factor {
                        int prime;
                        int power;
                } factorization[4]     = {0};
                int factorization_size = 0;
                int factors_count      = 0;
                for (int j = 0; j < primes_len; ++j) {
                        while (a[i] % primes[j] == 0) {
                                if (factors_count >= 3) goto dont_add;
                                factors_count++;
                                if (factorization_size &&
                                    factorization[factorization_size - 1]
                                            .prime == primes[j]) {
                                        factorization[factorization_size - 1]
                                            .power++;
                                } else {
                                        factorization[factorization_size++] =
                                            (struct Factor){primes[j], 1};
                                }
                                a[i] /= primes[j];
                        }
                }
#define NUM_DIVISORS                                                   \
        ((factorization[0].power + 1) * (factorization[1].power + 1) * \
         (factorization[2].power + 1))
                if (a[i] > 1) {
                        factorization[factorization_size++] =
                            (struct Factor){a[i], 1};
                }
                printf(" *** a[i] = %d, divisors: %d\n", number, NUM_DIVISORS);
                for (int j = 0; j < factorization_size; ++j) {
                        __builtin_dump_struct(&factorization[j], printf);
                }
                if (NUM_DIVISORS == 4) {
                        sum += 1 + number + factorization[0].prime +
                               number / factorization[0].prime;
                }
        dont_add:
        }
        return sum;
}
