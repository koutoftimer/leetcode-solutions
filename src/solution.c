#include "solution.h"

enum { KEY_CAPACITY = (int)1e6 + 1, VALUE_CAPACITY = (int)1e4 };

typedef struct {
        uint16_t keys[KEY_CAPACITY];  // enough to store 1e4 index
        int values[VALUE_CAPACITY];
        int size;
} MyHashMap;

#define myHashMapCreate() calloc(1, sizeof(MyHashMap))

void
myHashMapPut(MyHashMap* self, int key, int value)
{
        if (!self->keys[key]) {
                self->keys[key] = self->size++ + 1;
        }
        self->values[self->keys[key] - 1] = value;
}

int
myHashMapGet(MyHashMap* self, int key)
{
        if (!self->keys[key]) return -1;
        return self->values[self->keys[key] - 1];
}

#define myHashMapRemove(self, key) (self)->keys[key] = 0
#define myHashMapFree(obj)
