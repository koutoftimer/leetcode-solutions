#include "solution.h"

enum { MOD = (int)1e9 + 7 };

typedef struct {
        long d[2][2];
} mat22;

static mat22
mul(mat22 a, mat22 b)
{
        mat22 ret;
#define C(i, j) \
        ret.d[i][j] = (a.d[i][0] * b.d[0][j] + a.d[i][1] * b.d[1][j]) % MOD;
        C(0, 0);
        C(0, 1);
        C(1, 0);
        C(1, 1);
        return ret;
}

static mat22
bin_pow(mat22 a, int pow)
{
        mat22 b = {{{1, 0}, {0, 1}}};
        while (pow > 0) {
                if (pow % 2 == 0) {
                        pow /= 2;
                        a = mul(a, a);
                } else {
                        pow -= 1;
                        b = mul(b, a);
                }
        }
        return b;
}

int
numOfWays(int n)
{
        mat22 A   = {{{3, 2}, {2, 2}}};
        A         = bin_pow(A, n - 1);
        mat22 B   = {{{6, 0}, {6, 0}}};
        mat22 res = mul(A, B);
        return (res.d[0][0] + res.d[1][0]) % MOD;
}
