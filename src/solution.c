#include "solution.h"

// Inorder traversal of BST gives us sorted array, we can use it to calculate
// frequencis.
static void
count_freq(struct TreeNode* root, int* prev, int* count, int* max_count,
           int* stack_size)
{
        if (!root) return;
        count_freq(root->left, prev, count, max_count, stack_size);
        if (*prev == root->val) {
                *count += 1;
        } else {
                *count = 1;
        }
        if (*max_count < *count) {
                *max_count  = *count;
                *stack_size = 1;
        } else if (*max_count == *count) {
                *stack_size += 1;
        }
        *prev = root->val;
        count_freq(root->right, prev, count, max_count, stack_size);
}

static void
store(struct TreeNode* root, int* prev, int* count, int const max_count,
      int* stack_size, int* stack)
{
        if (!root) return;
        store(root->left, prev, count, max_count, stack_size, stack);
        if (*prev == root->val) {
                *count += 1;
        } else {
                *count = 1;
        }
        printf("count: %d\n", *count);
        if (*count == max_count) {
                stack[(*stack_size)++] = *prev;
        }
        *prev = root->val;
        store(root->right, prev, count, max_count, stack_size, stack);
}

int*
findMode(struct TreeNode* root, int* returnSize)
{
        int prev = INT_MAX;
        int count;
        int max_count  = INT_MIN;
        int stack_size = 0;
        count_freq(root, &prev, &count, &max_count, &stack_size);
        printf("prev: %d, count: %d, max_count: %d, stack_size: %d\n", prev,
               count, max_count, stack_size);
        int* stack = malloc(stack_size * sizeof(*stack));
        stack_size = count = 0;
        store(root, &prev, &count, max_count, &stack_size, stack);
        *returnSize = stack_size;
        return stack;
}
