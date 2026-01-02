#include "solution.h"

static int
impl(struct Node* root, int current)
{
        if (!root) return current;
        int max = current + 1;
        for (int i = 0; i < root->numChildren; ++i) {
                int depth = impl(root->children[i], current + 1);
                if (depth > max) max = depth;
        }
        return max;
}

#define maxDepth(root) impl(root, 0)
