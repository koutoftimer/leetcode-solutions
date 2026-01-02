#include "solution.h"

int
distributeCandies(int* candyType, int candyTypeSize)
{
        bool* eaten = calloc(200005, sizeof *eaten);
        int unique  = 0;
        for (int i = 0; i < candyTypeSize; ++i) {
                int index = candyType[i] + 100000;
                if (!eaten[index]) {
                        eaten[index] = true;
                        unique++;
                }
        }
        free(eaten);
        return MIN(unique, candyTypeSize / 2);
}
