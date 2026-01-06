#include "solution.h"

bool
rotateString(char* s, char* t)
{
        int const s_len = strlen(s);
        int const t_len = strlen(t);
        if (s_len != t_len) return false;
        if (memcmp(s, t, s_len) == 0) return true;
        for (int len = 1; len < s_len; ++len) {
                char* t_suffix = t + t_len - len;
                if (memcmp(s, t_suffix, len) != 0) {
                        continue;
                }
                int const remaining = s_len - len;
                char* s_suffix      = s + s_len - remaining;
                if (memcmp(s_suffix, t, remaining) == 0) {
                        return true;
                }
        }
        return false;
}
