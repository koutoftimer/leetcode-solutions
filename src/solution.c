#include "solution.h"

int findLUSlength(char* a, char* b) {
        int a_len = strlen(a);
        int b_len = strlen(b);
        if (a_len > b_len) return a_len;
        if (b_len > a_len) return b_len;
        return strcmp(a, b) == 0 ? -1 : a_len;
}
