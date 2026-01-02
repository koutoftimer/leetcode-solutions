#include "solution.h"

#define stack_push(value) stack[stack_size++] = value
#define stack_pop() stack[--stack_size]

int*
preorder(struct Node* root, int* returnSize)
{
        if (!root) {
                *returnSize = 0;
                return NULL;
        }
        int* res            = malloc(100000 * sizeof(*res));
        int size            = 0;
        struct Node** stack = malloc(100000 * sizeof(*res));
        int stack_size      = 0;
        stack_push(root);
        while (stack_size) {
                struct Node* node = stack_pop();
                res[size++]       = node->val;
                for (int i = node->numChildren - 1; i >= 0; --i) {
                        stack_push(node->children[i]);
                }
        }
        free(stack);
        *returnSize = size;
        return res;
}
