#include "solution.h"

static int dp[31] = {0, 1};

[[gnu::constructor]]
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
        return dp[n];
}
