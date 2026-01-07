#include "solution.h"

bool is_vowel['z' + 1] = {
    ['a'] = true, ['e'] = true, ['i'] = true, ['u'] = true, ['o'] = true,
    ['A'] = true, ['E'] = true, ['I'] = true, ['U'] = true, ['O'] = true,
};
char*
toGoatLatin(char* s)
{
        char* res = calloc(150 + 75 * 2 + 75 * (75 + 1) / 2 + 10, sizeof *res);
        int size  = 0;
        int a     = 1;
        while (*s) {
                char* space   = strchrnul(s, ' ');
                int const len = space - s;
                if (is_vowel[*s]) {
                        memcpy(res + size, s, len);
                        size += len;
                } else {
                        if (len > 1) {
                                memcpy(res + size, s + 1, len - 1);
                                size += len - 1;
                        }
                        res[size++] = *s;
                }
                res[size++] = 'm';
                res[size++] = 'a';
                for (int i = 0, n = a++; i < n; ++i) {
                        res[size++] = 'a';
                }
                if (*space) {
                        res[size++] = ' ';
                        space++;
                }
                s = space;
        }
        return res;
}
