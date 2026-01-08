#include "solution.h"

#define stack_push(stack, value) stack[++stack[0]] = (value)

static int
binary_search(int const* const a, int const len, int const needle)
{
        int low  = -1;
        int high = len;
        while (low + 1 < high) {
                int mid = low + (high - low) / 2;
                if (a[mid] >= needle) {
                        high = mid;
                } else {
                        low = mid;
                }
        }
        return high;
}

int
maxDotProduct(int* a, int a_len, int* b, int b_len)
{
        if (a_len < b_len) return maxDotProduct(b, b_len, a, a_len);

        // i => stack of j, such that a[i] + b[j] improves total
        int improve[a_len][b_len + 1];
        memset(improve, 0, sizeof improve);

        int can_improve = 0;
        int max_pair    = a[0] * b[0];
        for (int i = 0; i < a_len; ++i) {
                for (int j = 0; j < b_len; ++j) {
                        if (a[i] * b[j] > 0) {
                                stack_push(improve[i], j);
                        }
                        if (a[i] * b[j] > max_pair) {
                                max_pair = a[i] * b[j];
                        }
                }
                can_improve |= improve[i][0];
        }
        if (!can_improve) {
                return max_pair;
        }

        int dp[a_len + 1][b_len + 1];
        memset(dp, 0, sizeof dp);

        int i = a_len - 1;
        for (int j = b_len - 1; j >= 0; --j) {
                dp[i][j] = MAX(dp[i][j + 1], a[i] * b[j]) + d[i + 1][j + 1];
        }

        int i = a_len - 1;

        int r(int ai, int bj)
        {
                if (ai >= a_len || bj >= b_len) return 0;
                if (dp[ai][bj]) return dp[ai][bj];
                int max = 0;
                for (int i = ai; i < a_len; ++i) {
                        int const start =
                            binary_search(&improve[i][1], improve[i][0], bj) +
                            1;
                        for (int ij = start; ij <= improve[i][0]; ++ij) {
                                int const j       = improve[i][ij];
                                int const product = a[i] * b[j];
                                int const rec     = r(i + 1, j + 1);
                                if (product + rec > max) max = product + rec;
                        }
                }
                return dp[ai][bj] = max;
        }

        return r(0, 0);
}
