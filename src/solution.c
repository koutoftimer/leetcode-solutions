#include "solution.h"

enum { BASE = 31, MOD = (int)1e9 + 7 };

static inline long
prefix_hash(long* hash, int const len, long const mul)
{
        if (!len) return 0;
        return hash[len - 1] * mul % MOD;
}

static inline long
suffix_hash(long* hash, int const len, int const hash_len)
{
        return (hash[hash_len - 1] - hash[hash_len - len - 1] + MOD) % MOD;
}

static inline long
hash(long* hash, char* s, int i, long* powers)
{
        long const prev_hash = (i ? hash[i - 1] : 0);
        return (prev_hash + powers[i] * (s[i] - 'a' + 1)) % MOD;
}

bool
rotateString(char* s, char* t)
{
        int const s_len = strlen(s);
        int const t_len = strlen(t);
        if (s_len != t_len) return false;
        if (memcmp(s, t, s_len) == 0) return true;

        long powers[s_len];
        powers[0] = BASE;
        for (int i = 1; i < s_len; ++i) {
                powers[i] = powers[i - 1] * BASE % MOD;
        }

        long s_hash[s_len];
        long t_hash[s_len];
        for (int i = 0; i < s_len; ++i) {
                s_hash[i] = hash(s_hash, s, i, powers);
                t_hash[i] = hash(t_hash, t, i, powers);
        }

        for (int len = 1; len < s_len; ++len) {
                long mul           = powers[t_len - len - 1];
                long s_prefix_hash = prefix_hash(s_hash, len, mul);
                long t_suffix_hash = suffix_hash(t_hash, len, t_len);
                char* t_suffix     = t + t_len - len;
                if (s_prefix_hash != t_suffix_hash ||
                    memcmp(s, t_suffix, len) != 0) {
                        continue;
                }

                int const remaining = s_len - len;
                mul                 = powers[len - 1];
                long t_prefix_hash  = prefix_hash(t_hash, remaining, mul);
                long s_suffix_hash  = suffix_hash(s_hash, remaining, s_len);
                char* s_suffix      = s + s_len - remaining;
                if (s_suffix_hash == t_prefix_hash &&
                    memcmp(s_suffix, t, remaining) == 0) {
                        return true;
                }
        }

        return false;
}
