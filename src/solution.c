#include "solution.h"

enum { CAPACITY = (int)1e4 };

struct Stack {
        struct TreeNode** items;
        int size;
};

struct TreeNode** arena;

[[gnu::constructor]]
static void
init_stack()
{
        arena = malloc(2 * CAPACITY * sizeof *arena);
}

[[gnu::destructor]]
static void
free_stack()
{
        free(arena);
}

#define stack_push(stack, value) stack.items[stack.size++] = (value)
#define stack_pop(stack) stack.items[--stack.size]

int
maxLevelSum(struct TreeNode* root)
{
        int offset         = 0;
        struct Stack stack = {.items = arena + offset};
        offset ^= CAPACITY;

        stack_push(stack, root);

        int level = 1, min_level = level, max_sum = root->val;
        while (stack.size) {
                struct Stack next = {.items = arena + offset};
                offset ^= CAPACITY;

                int sum = 0;
                while (stack.size) {
                        struct TreeNode* node = stack_pop(stack);
                        if (node->left) {
                                sum += node->left->val;
                                stack_push(next, node->left);
                        }
                        if (node->right) {
                                sum += node->right->val;
                                stack_push(next, node->right);
                        }
                }

                level++;
                stack = next;
                if (sum > max_sum && stack.size) {
                        min_level = level;
                        max_sum   = sum;
                }
        }

        return min_level;
}
