#include "solution.h"

enum { CAPACITY = (int)2e4 + 1, NORMALIZATION = (int)1e4 };

bool* count;

[[gnu::constructor]]
static void
init_count()
{
        count = malloc(CAPACITY * sizeof *count);
}

[[gnu::destructor]]
static void
free_count()
{
        free(count);
}

static bool
impl(struct TreeNode* root, int k)
{
        if (!root) return false;
        int const to_find = k - root->val + NORMALIZATION;
        if (0 <= to_find && to_find < CAPACITY && count[to_find]) {
                return true;
        }
        int const current = root->val + NORMALIZATION;
        count[current]    = true;
        return impl(root->left, k) || impl(root->right, k);
}

static bool
findTarget(struct TreeNode* root, int k)
{
        memset(count, 0, CAPACITY);
        return impl(root, k);
}
