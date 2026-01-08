#include "solution.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(a, b)                         \
        do {                               \
                __typeof(a) __tmp = a;     \
                a                 = b;     \
                b                 = __tmp; \
        } while (0)

int
maxDotProduct(int* a, int a_len, int* b, int b_len)
{
        if (a_len < b_len) return maxDotProduct(b, b_len, a, a_len);

        int max_pair = a[0] * b[0];
        for (int i = 0; i < a_len; ++i) {
                for (int j = 0; j < b_len; ++j) {
                        int const product = a[i] * b[j];
                        if (product > max_pair) max_pair = product;
                }
        }
        if (max_pair <= 0) {
                return max_pair;
        }

        // min([start;stop)) for b[i]
        int min[b_len][b_len + 1];
        memset(min, 0, sizeof(min));
        // max([start;stop)) for b[i]
        int max[b_len][b_len + 1];
        memset(max, 0, sizeof(max));
        for (int start = 0; start < b_len; ++start) {
                max[start][start] = INT_MIN;
                min[start][start] = INT_MAX;
                for (int stop = start + 1; stop <= b_len; ++stop) {
                        max[start][stop] =
                            MAX(b[stop - 1], max[start][stop - 1]);
                        min[start][stop] =
                            MIN(b[stop - 1], min[start][stop - 1]);
                }
        }

        // dp(i, [start; stop))
        int dp_prev_mem[b_len + 1][b_len + 1];
        // zero means we can't improve total sum, only values > 0 counts in
        // total sum
        memset(dp_prev_mem, 0, sizeof dp_prev_mem);
        int dp_mem[b_len + 1][b_len + 1];
        memset(dp_mem, 0, sizeof dp_mem);

        int (*dp_prev)[b_len + 1] = dp_prev_mem;
        int (*dp)[b_len + 1]      = dp_mem;

        for (int i = a_len - 1; i >= 0; --i) {
                for (int start = 0; start < b_len; ++start) {
                        int dp_max = INT_MIN;
                        for (int stop = start + 1; stop <= b_len; ++stop) {
                                int value = dp_prev[start][stop];  // skip[i]
                                int const max_dp = a[i] * max[start][stop] +
                                                   dp_prev[stop][stop];
                                if (value < max_dp) value = max_dp;

                                int const min_dp = a[i] * min[start][stop] +
                                                   dp_prev[stop][stop];
                                if (value < min_dp) value = min_dp;
                                dp[start][stop] = value;
                                if (value > dp_max) dp_max = value;
                        }
                        dp[start][start] = dp_max;
                }
                SWAP(dp, dp_prev);
        }
        SWAP(dp, dp_prev);

        int ans = 0;
        for (int i = 1; i <= b_len; ++i) {
                if (ans < dp[0][i]) ans = dp[0][i];
        }
        return dp[0][0];
}
