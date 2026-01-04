#include "solution.h"

#define SWAP(a, b)                         \
        do {                               \
                __typeof(a) __tmp = a;     \
                a                 = b;     \
                b                 = __tmp; \
        } while (0)

enum { MAP_CAPACITY = 2003, PRIME = 97 };

static inline int
hash(char* s, int* len)
{
        uint res    = 1;
        char* start = s;
        while (*s) res = res * PRIME + *s++ - ' ' + 1;
        *len = s - start;
        return res % MAP_CAPACITY;
}

struct HashMap {
        int sum;  // of positions in A and B
        int len;
        char* s;
}* map;

[[gnu::constructor]]
static void
alloc_map()
{
        map = malloc(MAP_CAPACITY * sizeof *map);
}

[[gnu::destructor]]
static void
free_map()
{
        free(map);
}

static inline int
find_new(char* s, int* len)
{
        int index = hash(s, len);
        while (map[index].s) {
                index = (index + 1) % MAP_CAPACITY;
        }
        return index;
}

static inline int
find_existing(char* s)
{
        int len;
        int index = hash(s, &len);
        while (map[index].s &&
               (map[index].len != len || memcmp(s, map[index].s, len) != 0)) {
                index = (index + 1) % MAP_CAPACITY;
        }
        return index;
}

char**
findRestaurant(char** a, int a_len, char** b, int b_len, int* returnSize)
{
        if (a_len < b_len) {
                SWAP(a, b);
                SWAP(a_len, b_len);
        }
        memset(map, 0, MAP_CAPACITY * sizeof(*map));
        for (int i = 0; i < a_len; ++i) {
                int len;
                int index      = find_new(a[i], &len);
                map[index].s   = a[i];
                map[index].len = len;
                map[index].sum = i;
        }
        char** res  = malloc((a_len > b_len ? b_len : a_len) * sizeof *res);
        int size    = 0;
        int min_sum = INT_MAX;
        for (int j = 0; j < b_len; ++j) {
                int index             = find_existing(b[j]);
                struct HashMap* entry = &map[index];
                if (!entry->s) continue;  // if b[j] not in A
                entry->sum += j;
                if (entry->sum < min_sum) {
                        min_sum = entry->sum;
                        size    = 0;
                }
                if (entry->sum == min_sum) {
                        res[size++] = b[j];
                }
        }
        *returnSize = size;
        return res;
}
