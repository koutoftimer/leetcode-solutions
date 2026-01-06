#include "solution.h"

enum { CAPACITY = (int)1e4 };

struct Queue {
        struct TreeNode** items;
        int front;
        int back;
};

struct TreeNode** arena;

[[gnu::constructor]]
static void
init_stack()
{
        arena = malloc(CAPACITY * sizeof *arena);
}

[[gnu::destructor]]
static void
free_stack()
{
        free(arena);
}

#define queue_push(queue, value) queue.items[queue.back++] = (value)
#define queue_pop(queue) queue.items[queue.front++]
#define queue_size(queue) (queue.back - queue.front)

int
maxLevelSum(struct TreeNode* root)
{
        struct Queue queue = {.items = arena};

        queue_push(queue, root);

        int level = 1, min_level = level, max_sum = root->val;
        while (queue_size(queue)) {
                int sum = 0;
                for (int i = 0, n = queue_size(queue); i < n; ++i) {
                        struct TreeNode* node = queue_pop(queue);
                        if (node->left) {
                                sum += node->left->val;
                                queue_push(queue, node->left);
                        }
                        if (node->right) {
                                sum += node->right->val;
                                queue_push(queue, node->right);
                        }
                }

                level++;
                if (sum > max_sum && queue_size(queue)) {
                        min_level = level;
                        max_sum   = sum;
                }
        }

        return min_level;
}
