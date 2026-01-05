#include "solution.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int
tree_depth(struct TreeNode* root, int level)
{
        if (!root) return level;
        int const left  = tree_depth(root->left, level + 1);
        int const right = tree_depth(root->right, level + 1);
        return MAX(left, right);
}

double*
averageOfLevels(struct TreeNode* root, int* returnSize)
{
        int depth = tree_depth(root, 0);
        long sum[depth];
        int count[depth];
        memset(sum, 0, sizeof(sum));
        memset(count, 0, sizeof(count));
        void traverse(struct TreeNode * root, int level)
        {
                if (!root) return;
                sum[level] += root->val;
                count[level]++;
                traverse(root->left, level + 1);
                traverse(root->right, level + 1);
        }
        traverse(root, 0);
        double* res = malloc(depth * sizeof *res);
        for (int i = 0; i < depth; ++i) {
                res[i] = (double)sum[i] / count[i];
        }
        *returnSize = depth;
        return res;
}
