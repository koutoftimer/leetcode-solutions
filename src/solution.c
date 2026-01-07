#include "solution.h"

#define SWAP(a, b)                         \
        do {                               \
                __typeof(a) __tmp = a;     \
                a                 = b;     \
                b                 = __tmp; \
        } while (0)
bool
isRectangleOverlap(int* a, int a_len, int* b, int b_len)
{
        struct Rect {
                int x_start, y_start, x_stop, y_stop;
        };
        struct Rect const* left  = (struct Rect*)a;
        struct Rect const* right = (struct Rect*)b;
        if (left->x_start > right->x_start) SWAP(left, right);
        return right->x_start < left->x_stop && right->y_start < left->y_stop &&
               right->y_stop > left->y_start;
}
