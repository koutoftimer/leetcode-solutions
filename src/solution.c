#include "solution.h"

struct Stack {
        int items[200];
        int size;
};

#define is_leaf(root) (!(root)->left && !(root)->right)

static void
traverse(struct TreeNode* root, struct Stack* stack)
{
        if (!root) return;
        if (is_leaf(root)) {
                stack->items[stack->size++] = root->val;
        }
        traverse(root->left, stack);
        traverse(root->right, stack);
}

bool
leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
        struct Stack stack1 = {0}, stack2 = {0};
        traverse(root1, &stack1);
        traverse(root2, &stack2);
        return stack1.size == stack2.size &&
               memcmp(stack1.items, stack2.items,
                      stack1.size * sizeof *stack1.items) == 0;
}
