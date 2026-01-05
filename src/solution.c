#include "solution.h"

enum { CAPACITY = (int)1e6 + 1 };

typedef struct {
        bool* count;
} MyHashSet;

MyHashSet*
myHashSetCreate()
{
        MyHashSet* self = malloc(sizeof *self);
        self->count     = calloc(CAPACITY, sizeof *self->count);
        return self;
}

void
myHashSetAdd(MyHashSet* self, int key)
{
        self->count[key] = true;
}

void
myHashSetRemove(MyHashSet* self, int key)
{
        self->count[key] = false;
}

bool
myHashSetContains(MyHashSet* self, int key)
{
        return self->count[key];
}

void
myHashSetFree(MyHashSet* self)
{
        free(self->count);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);

 * myHashSetRemove(obj, key);

 * bool param_3 = myHashSetContains(obj, key);

 * myHashSetFree(obj);
*/
