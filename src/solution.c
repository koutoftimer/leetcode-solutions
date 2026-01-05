#include "solution.h"

bool
judgeCircle(char* moves)
{
        int dx = 0;
        int dy = 0;
        while (*moves) {
                switch (*moves++) {
                case 'R': {
                        dx++;
                } break;
                case 'L': {
                        dx--;
                } break;
                case 'U': {
                        dy++;
                } break;
                case 'D': {
                        dy--;
                } break;
                }
        }
        return !dx && !dy;
}
