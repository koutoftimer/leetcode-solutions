#include "solution.h"

static int
impl(struct TreeNode* root, int* sum)
{
        if (!root) return 0;
        root->val += impl(root->left, sum) + impl(root->right, sum);
        *sum += abs((root->left ? root->left->val : 0) -
                    (root->right ? root->right->val : 0));
        return root->val;
}

int
findTilt(struct TreeNode* root)
{
        int sum = 0;
        impl(root, &sum);
        return sum;
}
