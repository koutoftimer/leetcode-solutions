#include "solution.h"

static bool
matches(char* word, int* target)
{
        int count[26] = {0};
        while (*word) {
                count[*word++ - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
                if (count[i] < target[i]) return false;
        }
        return true;
}

char*
shortestCompletingWord(char* license, char** words, int size)
{
        int target[26] = {0};
        for (; *license; ++license) {
                if (!isalpha(*license)) continue;
                target[tolower(*license) - 'a']++;
        }

        char* res = NULL;
        int len;
        for (int i = 0; i < size; ++i) {
                int const new_len = strlen(words[i]);
                if ((!res || new_len < len) && matches(words[i], target)) {
                        len = new_len;
                        res = words[i];
                }
        }
        return res;
}
