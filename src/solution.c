#include "solution.h"

char* morze_codes[] = {
    ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
    ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
    "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--..",
};

static ulong
hash(char* word)
{
        ulong code = 1;
        while (*word) {
                char* sequence = morze_codes[*word++ - 'a'];
                while (*sequence) {
                        code <<= 1;
                        code |= *sequence++ == '.';
                }
        }
        return code;
}

enum { CAPACITY = 211 };

int
uniqueMorseRepresentations(char** words, int size)
{
        ulong hash_set[CAPACITY] = {0};
        int hash_set_size        = 0;
        for (int i = 0; i < size; ++i) {
                ulong word_hash = hash(words[i]);
                int index       = word_hash % CAPACITY;
                while (hash_set[index] && hash_set[index] != word_hash) {
                        index = (index + 1) % CAPACITY;
                }
                if (!hash_set[index]) {
                        hash_set_size++;
                        hash_set[index] = word_hash;
                }
        }
        return hash_set_size;
}
