#include "solution.h"

enum { CAPACITY = (int)1e4 };

int* sum;

int
maxLevelSum(struct TreeNode* root)
{
        memset(sum, 0, CAPACITY * sizeof *sum);
        int max_level = 0;
        void dfs(struct TreeNode * root, int level)
        {
                if (!root) return;
                dfs(root->left, level + 1);
                dfs(root->right, level + 1);
                sum[level - 1] += root->val;
                if (level > max_level) max_level = level;
        }
        dfs(root, 1);
        int min_level, max_sum = INT_MIN;
        for (int i = 0; i < max_level; ++i) {
                if (sum[i] > max_sum) {
                        max_sum   = sum[i];
                        min_level = i;
                }
        }
        return min_level - 1;
}

[[gnu::constructor]]
static void
init_stack()
{
        sum = malloc(CAPACITY * sizeof *sum);
}

[[gnu::destructor]]
static void
free_stack()
{
        free(sum);
}
