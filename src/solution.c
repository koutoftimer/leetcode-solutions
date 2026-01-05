#include "solution.h"

#define stack_push(x) stack[stack_size++] = (x)
#define stack_pop() stack[--stack_size]
#define stack_top() stack[stack_size - 1]

int
calPoints(char** operations, int operationsSize)
{
        int stack[1000];
        int stack_size = 0;
        for (int i = 0; i < operationsSize; ++i) {
                char const* const op = operations[i];
                switch (op[0]) {
                case '+': {
                        int const lhs = stack_pop();
                        int const rhs = stack_top();
                        stack_push(lhs);
                        stack_push(lhs + rhs);
                } break;
                case 'D': {
                        int const top = stack_top();
                        stack_push(top * 2);
                } break;
                case 'C': {
                        (void)stack_pop();
                } break;
                default: {
                        stack_push(atoi(op));
                }
                }
        }
        int sum = 0;
        for (int i = 0; i < stack_size; ++i) {
                sum += stack[i];
        }
        return sum;
}
