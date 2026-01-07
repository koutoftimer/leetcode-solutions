#include "solution.h"

struct HashMap {
        char* word;
        int count;
        UT_hash_handle hh;
};

struct HashMap* arena;
int arena_size;

void
process(char* s, struct HashMap** map)
{
        char* token = strtok(s, " ");
        while (token) {
                struct HashMap* entry;
                HASH_FIND_STR(*map, token, entry);
                if (!entry) {
                        entry        = arena + arena_size++;
                        entry->word  = token;
                        entry->count = 0;
                        HASH_ADD_STR(*map, word, entry);
                }
                entry->count++;
                token = strtok(NULL, " ");
        }
}

char**
uncommonFromSentences(char* s1, char* s2, int* returnSize)
{
        arena_size          = 0;
        struct HashMap* map = NULL;
        process(s1, &map);
        process(s2, &map);
        char** res = malloc(HASH_COUNT(map) * sizeof *res);
        int size   = 0;
        for (struct HashMap* entry = map; entry != NULL;
             entry                 = entry->hh.next) {
                if (entry->count == 1) res[size++] = strdup(entry->word);
        }
        HASH_CLEAR(hh, map);
        *returnSize = size;
        return res;
}

[[gnu::constructor]]
static void
malloc_arena()
{
        arena = malloc(200 * sizeof *arena);
}

[[gnu::destructor]]
static void
free_arena()
{
        free(arena);
}
