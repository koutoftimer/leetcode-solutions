#include "solution.h"

double
largestTriangleArea(int** points, int pointsSize, int* pointsColSize)
{
        long double area(int a, int b, int c)
        {
#define square(a) (a) * (a)
#define line_length(a, b)                           \
        sqrtl(square(points[a][0] - points[b][0]) + \
              square(points[a][1] - points[b][1]))
                long double const ab = line_length(a, b);
                long double const ac = line_length(a, c);
                long double const bc = line_length(b, c);
                long double const s  = (ab + ac + bc) / 2;
                return s * (s - ab) * (s - ac) * (s - bc);
        }
        long double max = -1;
        for (int a = 0; a < pointsSize; ++a) {
                for (int b = a + 1; b < pointsSize; ++b) {
                        for (int c = b = 1; c < pointsSize; ++c) {
                                long double current = area(a, b, c);
                                if (current > max) {
                                        max = current;
                                }
                        }
                }
        }
        return sqrtl(max);
}
