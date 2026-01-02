#include "solution.h"

bool
same(struct TreeNode* root, struct TreeNode* subRoot)
{
        if (!root && !subRoot) return true;
        if (!root || !subRoot) return false;
        if (root->val != subRoot->val) return false;
        return same(root->left, subRoot->left) &&
               same(root->right, subRoot->right);
}

bool
isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
        if (!root) return false;
        if (same(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
}
