#include "solution.h"

bool
buddyStrings(char* s, char* goal)
{
        int const s_len    = strlen(s);
        int const goal_len = strlen(goal);
        if (s_len != goal_len) {
                return false;
        }

        if (memcmp(s, goal, s_len) == 0) {
                uint bit_set = 0;
                while (*s) {
                        uint const mask = 1 << (*s++ - 'a');
                        if (bit_set & mask) {
                                return true;
                        }
                        bit_set |= mask;
                }
                return false;
        }

        int stack[3];
        int size = 0;
        for (int i = 0; size < 3 && i < s_len; ++i) {
                if (s[i] != goal[i]) {
                        stack[size++] = i;
                }
        }
        return size == 2 && s[stack[0]] == goal[stack[1]] &&
               s[stack[1]] == goal[stack[0]];
}
