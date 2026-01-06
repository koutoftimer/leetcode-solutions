#include "solution.h"

enum {
        CAPACITY = (int)1e6 + 1,
        BUCKETS  = (CAPACITY + 31) / 32,
};

typedef struct {
        uint* buckets;
} MyHashSet;

MyHashSet*
myHashSetCreate()
{
        MyHashSet* self = malloc(sizeof *self);
        self->buckets   = calloc(BUCKETS, sizeof *self->buckets);
        return self;
}

void
myHashSetAdd(MyHashSet* self, int key)
{
        uint const bucket_index = key / 32;
        uint const flag         = 1u << (key % 32);
        self->buckets[bucket_index] |= flag;
}

void
myHashSetRemove(MyHashSet* self, int key)
{
        uint const bucket_index = key / 32;
        uint const flag         = 1u << (key % 32);
        self->buckets[bucket_index] &= ~flag;
}

bool
myHashSetContains(MyHashSet* self, int key)
{
        uint const bucket_index = key / 32;
        uint const flag         = 1u << (key % 32);
        return self->buckets[bucket_index] & flag;
}

void
myHashSetFree(MyHashSet* self)
{
        free(self->buckets);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/
