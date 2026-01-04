#include "solution.h"

enum { MOD = (int)1e9 + 7 };

enum Color {
        R = 1 << 1,
        G = 1 << 2,
        Y = 1 << 3,
};

#define mask(r, g, b) ((r << 16) | (g << 8) | b)

static uint const combinations[] = {
    mask(R, Y, R), mask(R, Y, G), mask(R, G, R), mask(R, G, Y),
    mask(Y, R, Y), mask(Y, G, Y), mask(Y, G, R), mask(Y, R, G),
    mask(G, R, G), mask(G, Y, G), mask(G, Y, R), mask(G, R, Y),
};

static int dp[5001][ARRAY_SIZE(combinations)] = {0};

static long
r(int row, uint prev)
{
        if (row == 0) return 1;
        long matches = 0;
        for (uint i = 0; i < ARRAY_SIZE(combinations); ++i) {
                if ((combinations[i] & prev) == 0) {
                        if (dp[row][i]) {
                                matches += dp[row][i];
                        } else {
                                matches += dp[row][i] =
                                    r(row - 1, combinations[i]) % MOD;
                        }
                        matches %= MOD;
                }
        }
        return matches;
}

int
numOfWays(int n)
{
        return r(n, 0);
}
