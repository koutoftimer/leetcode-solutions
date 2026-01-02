#include "solution.h"

#define stack_push(value) stack[stack_size++] = (value)
#define stack_pop() stack[--stack_size]
#define stack_top() stack[stack_size - 1]

int*
postorder(struct Node* root, int* returnSize)
{
        int* res            = malloc(10001 * sizeof(*res));
        int size            = 0;
        struct Node** stack = malloc(10001 * sizeof(*stack));
        int stack_size      = 0;
        stack_push(root);
        while (stack_size) {
                struct Node* node = stack_pop();
                if (!node) continue;
                res[size++] = node->val;
                for (int i = 0; i < node->numChildren; ++i) {
                        stack_push(node->children[i]);
                }
        }
        int *l = res, *r = res + size - 1;
        while (l < r) {
                int tmp = *l;
                *l++    = *r;
                *r--    = tmp;
        }
        *returnSize = size;
        free(stack);
        return res;
}
