#include "solution.h"

int stack[200];
int stack_size;

#define is_leaf(root) (!(root)->left && !(root)->right)

static void
traverse(struct TreeNode* root)
{
        if (!root) return;
        if (is_leaf(root)) {
                stack[stack_size++] = root->val;
        }
        traverse(root->left);
        traverse(root->right);
}

static bool
reverse(struct TreeNode* root)
{
        if (!root) return true;
        if (is_leaf(root)) {
                if (!stack_size) return false;
                int const value = stack[--stack_size];
                if (value != root->val) return false;
        }
        return reverse(root->right) && reverse(root->left);
}

bool
leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
        stack_size = 0;
        traverse(root1);
        return reverse(root2) && !stack_size;
}
