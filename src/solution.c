#include "solution.h"

double
largestTriangleArea(int** points, int pointsSize, int* pointsColSize)
{
        int area(int a, int b, int c)
        {
                int const x1 = points[a][0];
                int const x2 = points[b][0];
                int const x3 = points[c][0];
                int const y1 = points[a][1];
                int const y2 = points[b][1];
                int const y3 = points[c][1];
                int const res =
                    x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
                return abs(res);
        }
        int max = -1;
        for (int a = 0; a < pointsSize; ++a) {
                for (int b = a + 1; b < pointsSize; ++b) {
                        for (int c = b + 1; c < pointsSize; ++c) {
                                long current = area(a, b, c);
                                if (current > max) {
                                        max = current;
                                }
                        }
                }
        }
        return sqrt(0.5 * max);
}
