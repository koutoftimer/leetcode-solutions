#include "solution.h"

struct {
        int dx;
        int dy;
} changes[] = {
    ['L'] = {.dx = -1},
    ['R'] = {.dx = 1},
    ['D'] = {.dy = -1},
    ['U'] = {.dy = 1},
};

bool
judgeCircle(char* moves)
{
        int dx = 0;
        int dy = 0;
        while (*moves) {
                char const move = *moves++;
                dx += changes[move].dx;
                dy += changes[move].dy;
        }
        return !dx && !dy;
}
