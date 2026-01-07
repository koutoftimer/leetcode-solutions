#include "solution.h"

char*
mostCommonWord(char* paragraph, char** banned, int bannedSize)
{
        struct BannedHash {
                char* word;
                UT_hash_handle hh;
        }* banned_hash = NULL;
        for (int i = 0; i < bannedSize; ++i) {
                struct BannedHash* node = malloc(sizeof *node);
                node->word              = banned[i];
                HASH_ADD_STR(banned_hash, word, node);
        }

        struct FrequencyHash {
                char* word;
                uint count;
                UT_hash_handle hh;
        }* frequency = NULL;

        char* res;
        uint max_frequency = 0;
        while (*paragraph) {
                while (*paragraph && !isalpha(*paragraph)) paragraph++;
                char* const start = paragraph;
                if (!*start) continue;
                for (; *paragraph && isalpha(*paragraph); ++paragraph) {
                        *paragraph = tolower(*paragraph);
                }
                if (*paragraph) {
                        *paragraph++ = '\0';
                }
                char* const word = start;

                struct BannedHash* is_banned;
                HASH_FIND_STR(banned_hash, word, is_banned);
                if (is_banned) continue;

                struct FrequencyHash* node;
                HASH_FIND_STR(frequency, word, node);
                if (!node) {
                        node        = malloc(sizeof *node);
                        node->word  = word;
                        node->count = 0;
                        HASH_ADD_STR(frequency, word, node);
                }
                node->count++;
                if (node->count > max_frequency) {
                        max_frequency = node->count;
                        res           = word;
                }
        }
        return res;
}
