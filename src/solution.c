#include "solution.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
bool
isRectangleOverlap(int* a, int a_len, int* b, int b_len)
{
        struct Rect {
                int x_start, y_start, x_stop, y_stop;
        };
        struct Rect const* left  = (struct Rect*)a;
        struct Rect const* right = (struct Rect*)b;
        return MIN(left->y_stop, right->y_stop) >
                   MAX(left->y_start, right->y_start) &&
               MIN(left->x_stop, right->x_stop) >
                   MAX(left->x_start, right->x_start);
}
