#include "solution.h"

struct TreeNode*
mergeTrees(struct TreeNode* a, struct TreeNode* b)
{
        if (!a && !b) return NULL;
        if (!a) return b;
        if (!b) return a;
        a->val += b->val;
        a->left  = mergeTrees(a->left, b->left);
        a->right = mergeTrees(a->right, b->right);
        return a;
}
