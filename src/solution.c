#include "solution.h"

static bool
tree_contains(struct TreeNode* root, struct TreeNode* skip, int value)
{
        if (!root) return false;
        if (root != skip && root->val == value) return true;
        if (value < root->val) return tree_contains(root->left, skip, value);
        return tree_contains(root->right, skip, value);
}

bool
findTarget(struct TreeNode* root, int k)
{
        bool traverse(struct TreeNode * current)
        {
                if (!current) return false;
                return tree_contains(root, current, k - current->val) ||
                       traverse(current->left) || traverse(current->right);
        }
        return traverse(root);
}
