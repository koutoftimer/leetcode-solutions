#include "solution.h"

char*
convertToBase7(int num)
{
        char* res = calloc(20, sizeof(*res));
        char* l   = res;
        int size  = 0;
        if (num < 0) res[size++] = '-', l = res + 1, num = -num;
        if (num == 0) res[size++] = '0';
        while (num) {
                res[size++] = '0' + num % 7;
                num /= 7;
        }
        char* r = res + size - 1;
        while (l < r) {
                char tmp = *l;
                *l++     = *r;
                *r--     = tmp;
        }
        return res;
}
