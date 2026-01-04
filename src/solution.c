#include "solution.h"

enum { BUCKETS_COUNT = 32768 };

struct Bucket {
        int key;
        int count;
};

static inline uint
hash(int key)
{
        return key * 2654435761u & (BUCKETS_COUNT - 1);
}

static inline int
find(struct Bucket* map, int const key)
{
        int index = hash(key);
        while (map[index].count && map[index].key != key) {
                index = (index + 1) & (BUCKETS_COUNT & 1);
        }
        return index;
}

int
findLHS(int* a, int size)
{
        // asm("int3");
        struct Bucket map[BUCKETS_COUNT] = {0};
        int max                          = 0;
        for (int i = 0; i < size; ++i) {
                int current      = find(map, a[i]);
                map[current].key = a[i];
                map[current].count++;
                int prev = find(map, a[i] - 1);
                if (map[prev].count &&
                    map[current].count + map[prev].count > max) {
                        max = map[current].count + map[prev].count;
                }
                int next = find(map, a[i] + 1);
                if (map[next].count &&
                    map[current].count + map[next].count > max) {
                        max = map[current].count + map[next].count;
                }
                printf(
                    "a[%d] = %d, current: %d->%d, prev: %d->%d, next: %d->%d\n",
                    i, a[i], map[current].key, map[current].count,
                    map[prev].key, map[prev].count, map[next].key,
                    map[next].count);
        }
        return max;
}
