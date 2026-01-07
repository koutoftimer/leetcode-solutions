#include "solution.h"

bool
lemonadeChange(int* bills, int billsSize)
{
        int count[21] = {0};
        for (int i = 0; i < billsSize; ++i) {
                switch (bills[i]) {
                case 5: {
                        count[5]++;
                } break;
                case 10: {
                        if (!count[5]--) return false;
                        count[10]++;
                } break;
                case 20: {
                        if (count[5] && count[10]) {
                                count[5]--, count[10]--;
                        } else if (count[5] >= 3) {
                                count[5] -= 3;
                        } else {
                                return false;
                        }
                } break;
                }
        }
        return true;
}
