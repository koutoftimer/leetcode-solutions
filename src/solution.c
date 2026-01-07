#include "solution.h"

bool
buddyStrings(char* s, char* goal)
{
        int const s_len    = strlen(s);
        int const goal_len = strlen(goal);
        if (s_len != goal_len) {
                return false;
        }
        int count_s[26]    = {0};
        int count_goal[26] = {0};
        for (int i = 0; i < s_len; ++i) {
                count_s[s[i] - 'a']++;
                count_goal[goal[i] - 'a']++;
        }
        if (memcmp(count_s, count_goal, sizeof(count_s)) != 0) {
                return false;
        }
        int diff = 0;
        while (*s) {
                diff += *s++ != *goal++;
        }
        if (diff == 2) return true;
        if (diff != 0) return false;
        for (int i = 0; i < 26; ++i) {
                if (count_s[i] > 1) return true;
        }
        return false;
}
