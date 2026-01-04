#include "solution.h"

enum { MOD = (int)1e9 + 7 };

typedef struct {
        uint64_t d[10][10];
} mat;

static mat
mul(mat const a, mat const b)
{
        mat res = {0};
        for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                        for (int k = 0; k < 10; ++k) {
                                res.d[i][j] += (a.d[i][k] * b.d[k][j]) % MOD;
                        }
                        res.d[i][j] %= MOD;
                }
        }
        return res;
}

static mat
binary_power(mat a, int power)
{
        mat b = {0};
        for (int i = 0; i < 10; i++) b.d[i][i] = 1;
        while (power) {
                if (power % 2 == 0) {
                        power /= 2;
                        a = mul(a, a);
                } else {
                        power -= 1;
                        b = mul(a, b);
                }
        }
        return b;
}

int
knightDialer(int n)
{
        mat M    = {{
            {[4] = 1, [6] = 1},           // 0
            {[6] = 1, [8] = 1},           // 1
            {[7] = 1, [9] = 1},           // 2
            {[4] = 1, [8] = 1},           // 3
            {[0] = 1, [3] = 1, [9] = 1},  // 4
            {},                           // 5
            {[0] = 1, [1] = 1, [7] = 1},  // 6
            {[2] = 1, [6] = 1},           // 7
            {[1] = 1, [3] = 1},           // 8
            {[2] = 1, [4] = 1},           // 9
        }};
        M        = binary_power(M, n - 1);
        mat res  = {{{[0 ... 9] = 1}}};
        res      = mul(res, M);
        long sum = 0;
        for (int i = 0; i < 10; ++i) sum += res.d[0][i];
        return sum % MOD;
}
