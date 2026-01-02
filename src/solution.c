#include "solution.h"

static int
get_size(struct Node* root)
{
        if (!root) return 0;
        int size = 0;
        for (int i = 0; i < root->numChildren; ++i) {
                size += get_size(root->children[i]);
        }
        return 1 + root->numChildren + size;
}

static void
traversal(struct Node* root, int* res, int* size)
{
        if (!root) return;
        res[(*size)++] = root->val;
        for (int i = 0; i < root->numChildren; ++i) {
                traversal(root->children[i], res, size);
        }
}

int*
preorder(struct Node* root, int* returnSize)
{
        int size    = get_size(root);
        int* res    = malloc(size * sizeof(*res));
        *returnSize = 0;
        traversal(root, res, returnSize);
        return res;
}
