#include "solution.h"

static int dp[31] = {0, 1};

static void
init_fib()
{
        for (int i = 2; i <= 30; ++i) {
                dp[i] = dp[i - 2] + dp[i - 1];
        }
}

int
fib(int n)
{
        static pthread_once_t ONCE = PTHREAD_ONCE_INIT;
        pthread_once(&ONCE, init_fib);
        return dp[n];
}
