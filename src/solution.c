#include "solution.h"

// Inorder traversal gives us sorted sequence, which we can use
static int
impl(struct TreeNode* root, int* prev)
{
        if (!root) return INT_MAX;
        int a = impl(root->left, prev);
        int b = *prev == -1 ? root->val : abs(*prev - root->val);
        *prev = root->val;
        int c = impl(root->right, prev);
        return a < b && a < c ? a : (b < c ? b : c);
}

int
getMinimumDifference(struct TreeNode* root)
{
        int prev = -1;
        return impl(root, &prev);
}
