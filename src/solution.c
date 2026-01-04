#include "solution.h"

enum { MAP_CAPACITY = 2003 };

static inline int
hash(char* s)
{
        uint res = 1;
        while (*s) {
                res = (res + *s++) * 31 | (res >> 16);
        }
        return res % MAP_CAPACITY;
}

struct HashMap {
        int i;  // min pos in a
        int j;  // min pos in b
        char* s;
}* map;

static inline int
find(char* s)
{
        int index = hash(s);
        while (map[index].s && strcmp(s, map[index].s) != 0) {
                index = (index + 1) % MAP_CAPACITY;
        }
        return index;
}

char**
findRestaurant(char** a, int a_len, char** b, int b_len, int* returnSize)
{
        map = calloc(MAP_CAPACITY, sizeof *map);
        for (int i = 0; i < a_len; ++i) {
                int index = find(a[i]);
                if (map[index].i) continue;
                map[index].s = a[i];
                map[index].i = i + 1;
        }
        for (int j = 0; j < b_len; ++j) {
                int index = find(b[j]);
                if (map[index].j) continue;
                map[index].j = j + 1;
        }

        char** res  = malloc((a_len > b_len ? b_len : a_len) * sizeof *res);
        int size    = 0;
        int min_sum = INT_MAX;
        for (int i = 0; i < MAP_CAPACITY; ++i) {
                if (!map[i].i || !map[i].j) continue;
                if (map[i].i + map[i].j < min_sum) {
                        min_sum = map[i].i + map[i].j;
                        size    = 0;
                }
                if (map[i].i + map[i].j == min_sum) {
                        res[size++] = map[i].s;
                }
        }

        free(map);
        *returnSize = size;
        return res;
}
